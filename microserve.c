asm(".MARK_MICROSERVER:");

// LICENSE CC-BY-SA 4.0
// 2025 misc147, www.github.com/michael105

#define VERSION "0.1.rc4"

// path to sh. needed for directory listings and markdown converting
#define SHPATH "/bin/sh"
#define BUFSIZE 4000

#include "mimetypes.h"

void __attribute__((noreturn)) err( int err, const char* msg ){
	eprints( "ERROR: ",msg, "\n" );
	exit(ERRNO(err));
}

# define warning(_errno, _msg ) { ewrites( "WARN: " _msg "\n" ); }

#if __BYTEORDER == __LITTLE_ENDIAN
#define HTONS16(_x) ( ((_x&0xff) <<8)|((_x>>8)&0xff) )
#else
#define HTONS16(_x) (_x)
#endif



static void send_header( const char* status, const char* phrase, int mimetype ){
	prints( "HTTP/1.0 ", status, " ",phrase, "\r\n"
			"Server: micro_httpd " VERSION ".misc147\r\n" 
			"Connection: close\r\n"
			"Public: GET\r\n"
			"Content-Type: ",MIMESTR(mimetype),"\r\n\r\n"
			); 
}
	
static void send_htmlhead(const char* status, const char* title ){
	prints("<html>\n<head><title>",status,": ", title, 
			"</title></head>\n<body>\n<h3>", status, ": ", title, "</h3>\n" );
}

static void send_error( char*status, char*title ){
	eprints( status, ": ", title, "\n");
	// insert some delay for bad requests. stripped that.
	// usleep( 2000000 ); 
	send_header( status, title, MIMETYPE(html) );
	send_htmlhead(status,title);
	writes("</body></html>\n" );
	// usleep( 5000000 ); 

	exit(0);
}

#define BUFOFFS 4

static void __attribute__((noreturn))http_handler( int rfd, char *buf, char *pos, int ruid ){
	
	int r;
	do {
		//r = recv(rfd, pos, (BUFSIZE-(pos-buf)), 0 );
		r= read(rfd, pos, (BUFSIZE-(pos-buf)) );
	} while ( ERRNO(r) == EINTR || ERRNO(r) == EAGAIN );

	if ( r<0 || r >= (BUFSIZE-(pos-buf)) ) // might be junk, or something else happened
			send_error("413", "Bad");

	// parsing is little bit nasty. anyways. assume, the clients will adapt.
	// It is their fault!
	if ( ((*(uint*)pos) & 0xffffff) != *(uint*)"GET" ){ // little endian
		send_error("405","Unsupported" );
	}

	// Got a new customer
	char *path = pos+4;
	char *p = path;

	// no encoded chars. or umlauts. or.. 
	while ( (*(++p) > 32) && (*p<127) && (p-path < r) );

	if ( !*p || *p>32 || (p-path==r ) )
			send_error("400","Bad path");
	*p = 0;
	int pathlen = p-pos-4;

	eprintsl( path, " == ",buf+4 );

	// Somehow unecessary checks. This should be used locally only. Anyways.
	if ( pathlen > PATH_MAX - (pos-buf) )
		send_error("400","Bad Request");

	if ( path[0] != '/' )
		send_error("400","Bad Path");

	for ( char *c = path; *c; c++ )
		if ( *c=='.' && *(c+1) == '.' )
			send_error("418","Bad Path"); 

	char *pend = stpcpy( pos, path );
	path = buf+4;

	eprints("Access: ",path,"\n");

	struct stat st;
	if ( stat( path, &st ) != 0 ){ 
		send_error("404","Not found");
	}

	if ( ruid>=0 && st.st_uid != ruid )
		send_error("403","Forbidden");

	int mimetype = getmimetype(path);
	
	char *args[] = { "sh", "-c", buf,  0 };
	int ffd = 0;

	if ( S_ISDIR( st.st_mode ) ){
		mimetype = MIMETYPE(html);
	} else 

		if ( mimetype == MIMETYPE( markdown ) ){
		*(uint*)buf = *(uint*)"cat ";
		strcpy( pend, " | lowdown -s" );
		mimetype = MIMETYPE(html);

	} else {
		ffd = open( path, O_RDONLY );
		if ( ffd<=0 )
			send_error("423", "Not accessible" );
	}

	send_header( "200", "Ok", mimetype );

	if ( S_ISDIR( st.st_mode ) ){
		//int plen = pend-pos;

		send_htmlhead( "Directory index", pos );

		if (pathlen>1) prints( "<a href=\"",pos,"/..\">Parent .. &uarr;</a><br/>\n" ); 

		*(uint*)buf = *(uint*)"ls  ";

		pend = stpcpy(pend, " | sed -E 's;(.*);<a href=\\\""); 
		memcpy(pend, pos+1, pathlen-1 );
		strcpy(pend+pathlen-1, "/\\1\\\">\\1</a><br/>;';" 
				"echo '</body></html>'");

		//eprints( "dir: ", (buf), "\n" );
	} 	

	if ( ffd == 0 ){
		execve( SHPATH, args, 0 );
	} else {
		sendfile(1, ffd, 0, st.st_size );
	}

	//close(rfd); // bloats. the kernel closes in each case.
	//close(ffd);
	exit(0);
}


int __attribute__((used))main(int argc, char **argv, char **env){

	if ( argc < 2 || argv[1][0] == '-' ){
		ewrites("Usage: micro_httpd path [port] [restrict uid]\n");
		exit(1);
	}

	char _buf[BUFSIZE+BUFOFFS];
	//char *_buf = (char*)mmap( 0, (BUFSIZE+BUFOFFS), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, 0, 0 );
	char *buf = _buf + BUFOFFS;
	char *pos = stpcpy( buf, argv[1] );
	//if ( *(pos-1) != '/' )
	//	*pos++ = '/';

	int rfd;
	socklen_t addrlen;
	struct sockaddr_in address;
	int sockfd;
	int ruid=-1;

		// Check for successful socket initialization
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) <= 0){
		err(sockfd,"socket");
	}

	// Set binding parameters
	int port = 0;
	if ( argc>2 )
		for ( const char *p = argv[2]; *p>='0' && *p<='9'; p++ )
			port = port*10 + *p-'0';

	if ( argc>3 ){
		ruid=0;
		for ( const char *p = argv[3]; *p>='0' && *p<='9'; p++ )
			ruid = ruid*10 + *p-'0';
	}


	if ( !port ) port = 4000;

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = HTONS16(port); // 0xa00f; // port 4000

	int r;
	ulong l = 1;
	if ( (r =setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &l, sizeof(l))) < 0){
		err(r,"socket options" );
	}


	if ( (r=bind(sockfd, (struct sockaddr *) &address, sizeof(address))) != 0){
		err(r,"binding socket" );
	}

	eprintsl("serve at port ",(argc>2?argv[2]:"4000"),", root: ", buf );

	
	//ewritesl("listen");
	if ( (r=listen(sockfd, 10)) < 0)
		err( r, "listen" );

	do {
		//ewritesl("accept");
		uint retr = 0;
		while ((rfd = accept(sockfd, (struct sockaddr *) &address, &addrlen)) < 0){
			warning(rfd,"accept");
			retr = (retr+1) & 0x8;
			usleep(10000*retr*retr); // max 8*8*1/100 seconds
		}

		ewrites("Connect\n");

		// Spawns a child process which handles the request
		int pid = fork();
		if (pid < 0){
			warning(pid,"fork");
		}

		// If child process, close the request socket, and initiate the
		// handler
		if (pid == 0){
			close(sockfd);
			close(1);
			dup(rfd);
			http_handler(rfd,_buf, pos,ruid);
		}
		// If parent process, close the response socket
		else {
			close(rfd);
		}
	} while(1);

	__builtin_unreachable();
}





	
	
	
		
