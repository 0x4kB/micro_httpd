asm(".MARK_MICROSERVER:");

// LICENSE BSD 3clause
// 2025 misc147, www.github.com/michael105

#define VERSION "0.1.rc"

#define BUFSIZE 4000


//# define err(_errno, _msg ) { ewrites( "ERR: " _msg "\n" ); exit(_errno); }

void __attribute__((noreturn)) err( int err, const char* msg ){
	eprints( "ERROR: ",msg, "\n" );
	exit(ERRNO(err));
}

# define warning(_errno, _msg ) { ewrites( "WARN: " _msg "\n" ); }


#define _MIMETYPES \
  _MIME ( UNKNOWN, unknown, "application/octet-stream", "\e" ) \
  _MIME ( msword, application_msword, "application/msword", ".doc" ) \
  _MIME ( octet_stream, application_octet_stream, "application/octet-stream", ".bin\t.rar" ) \
  _MIME ( pdf, application_pdf, "application/pdf", ".pdf" ) \
  _MIME ( javascript, application_x_javascript, "application/x-javascript", ".js" ) \
  _MIME ( xml, application_xml, "application/xml", ".xml" ) \
  _MIME ( zip, application_zip, "application/zip", ".zip" ) \
  _MIME ( gz, image_gz, "application/gz", ".gz" ) \
  _MIME ( tar, image_tar, "application/tar", ".tar" ) \
  _MIME ( mp3, audio_mpeg3, "audio/mpeg3", ".mp3" ) \
  _MIME ( bmp, image_bmp, "image/bmp", ".bmp" ) \
  _MIME ( gif, image_gif, "image/gif", ".gif" ) \
  _MIME ( ico, image_ico, "image/ico", ".ico" ) \
  _MIME ( jpeg, image_jpeg, "image/jpeg", ".jpeg\t.jpg" ) \
  _MIME ( png, image_png, "image/png", ".png" ) \
  _MIME ( tiff, image_tiff, "image/tiff", ".tiff" ) \
  _MIME ( css, text_css, "text/css", ".css" ) \
  _MIME ( html, text_html, "text/html", ".html\t.shtml\t.htm\t.php" ) \
  _MIME ( markdown, text_markdown, "text/markdown", ".markdown\t.md" ) \
  _MIME ( plain, text_plain, "text/plain", "README\t.nfo\t.txt" ) \
  _MIME ( c, text_x_c, "text/x-c", ".c\t.h" ) \
  _MIME ( avi, video_avi, "video/avi", ".avi" ) \
  _MIME ( mpg, video_mpeg, "video/mpeg", ".mpeg\t.mpg" ) \


#define _MIME(_s,_e,_t,_ext) _t,
const char * const mimetypes_str[] ={
	_MIMETYPES
};
#undef _MIME
#define _MIME(_s,_e,_t,_ext) "\n"_ext,
const char * const mimetypes_ext[] ={
	_MIMETYPES
};
#undef _MIME

#define _MIME(_s,_e,_t,_ext) _s,_e=_s,
#define _MIME_ENUM enum { _MIMETYPES ENDENUM }

// return enum value of _mime ( png, image_png, markdown, text_markdown, .. )
#define MIMETYPE(_type) ({ _MIME_ENUM; _type; })

// return a pointer to the mimetype (no check of bounds)
#define MIMETYPE_STR(_mimetype) ({ _MIME_ENUM; mimetypes_str[_mimetype]; })


// return the mimetype number
static int getmimetype(const char* path){
	const char *pend = path + strlen(path) - 1;

	int type = 0;
	for ( const char *const *m = mimetypes_ext; m - mimetypes_ext < sizeof(mimetypes_ext)/sizeof(char*); m++ ){
		const char *p, *pext=(*m+(strlen(*m)));
		do {
			p = pend;
			pext--;
			while ( *p && (tolower(*p)==*pext) ){
				 p--; pext--;
			}
			if ( *pext <= '\n' ){
				return( m - mimetypes_ext );
			}
			while ( *pext > '\n' ){
				pext--;
			}

		}
		while ( *pext != '\n' );
	}

	return(MIMETYPE(unknown));
}



static void sendheader( char*status, char*title, int mimetype ){
	prints( "HTTP/1.0 ", status, " ",title, "\r\n"
			"Server: micro_httpd " VERSION ".misc147\r\n" 
			"Connection: close\r\n"
			"Allow: GET\r\n"
			"Content-Type: ",mimetypes_str[mimetype],"\r\n\r\n"
			); 
}
	
static void send_htmlhead(const char* status, const char* title ){
	prints("<html>\n<head><title>",status,": ", title, 
			"</title></head>\n<body>\n<h3>", status, ": ", title, "</h3>\n" );
}

static void send_error( char*status, char*title ){
	eprints( status, ": ", title, "\n");
	sendheader( status, title, MIMETYPE(html) );
	send_htmlhead(status,title);
	writes("</body></html>\n" );

	exit(0);
}

#define BUFOFFS 4

static void __attribute__((noreturn))http_handler( int rfd, char *buf, char *pos ){
	
	int r;
	do {
		//r = recv(rfd, pos, (BUFSIZE-(pos-buf)), 0 );
		r= read(rfd, pos, (BUFSIZE-(pos-buf)) );
	} while ( ERRNO(r) == EINTR || ERRNO(r) == EAGAIN );

	if ( r<0 || r == (BUFSIZE-(pos-buf)) ) // might be junk, or something else happened
			send_error("400", "Bad");

	//eprints( pos );
	char *p;
	
	// fuzzy parsing
	char* method = strtok_r( pos, " \t\n\r", &p );
	char* path = strtok_r( 0, " \t\n\r", &p );
	char* prot = strtok_r( 0, " \t\n\r", &p );


	// ignore the rest. 

	//if ( strncasecmp( "get", method, 3 ) )
	if ( strcmp( "GET", method ) )
		send_error("405","Unsupported" );


	// Somehow unecessary checks. This should be used locally only. Anyways.
	if ( prot-path > PATH_MAX - (pos-buf) )
		send_error("400","Bad Request");

	if ( path[0] != '/' )
		send_error("400","Bad Path");

	for ( char *c = path; *c; c++ )
		if ( *c=='.' && *(c+1) == '.' )
			send_error("400","Bad Path ..");

	char *pend = stpcpy( pos, path );
	path = buf+BUFOFFS;

	eprints("Access: ",path,"\n");

	struct stat st;
	if ( stat( path, &st ) != 0 ){ 
		send_error("404","Not found");
	}

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

	sendheader( "200", "Ok", mimetype );

	if ( S_ISDIR( st.st_mode ) ){
		int plen = pend-pos;

		send_htmlhead( "Directory index", pos );

		if (plen>1) prints( "<a href=\"",pos,"/..\">Parent .. &uarr;</a><br/>\n" ); 

		*(uint*)buf = *(uint*)"ls  ";
		char *p = pend;// pend+=plen;
		pend = stpcpy(pend, " | sed -E 's;(.*);<a href=\\\""); 
		memcpy(pend, pos+1, plen-1 );
		strcpy(pend+plen-1, "/\\1\\\">\\1</a><br/>;';" 
				"echo '</body></html>'");

		//eprints( "dir: ", (buf), "\n" );
	} 	

	if ( ffd == 0 ){
		execve( "/bin/sh", args, 0 );
	} else {
		sendfile(1, ffd, 0, st.st_size );
	}

	//close(rfd); // bloats. the kernel closes in each case.
	//close(ffd);
	exit(0);
}


int __attribute__((used))main(int argc, char **argv, char **env){

	if ( argc != 2 || argv[1][0] == '-' ){
		ewrites("Usage: microserve pathname\n");
		exit(1);
	}


	char _buf[BUFSIZE+BUFOFFS];
	char *buf = _buf + BUFOFFS;
	char *pos = stpcpy( buf, argv[1] );
	//if ( *(pos-1) != '/' )
	//	*pos++ = '/';

	int rfd;
	socklen_t addrlen;
	struct sockaddr_in address;
	int sockfd;

		// Check for successful socket initialization
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) <= 0){
		err(sockfd,"socket creation");
	}

	// Set binding parameters
	//int port = 4000;

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = 0xa00f; // port 4000, htons(4000)

	int r;
	ulong l = 1;
	if ( (r =setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &l, sizeof(l))) < 0){
		err(r,"socket options" );
	}


	if ( (r=bind(sockfd, (struct sockaddr *) &address, sizeof(address))) != 0){
		err(r,"binding socket" );
	}

	eprintsl("serve at port 4000, root: ", buf );

	int retr = 0;
	while (1) {
		// Check for incoming client connections
		//ewritesl("listen");
		if ( (r=listen(sockfd, 10)) < 0) {
			warning(r,"listen");
			if ( ++retr > 10 )
				err(EFAULT,"abort");
			usleep(100);
			continue;
		}
		retr=0;

		//ewritesl("accept");
		if ((rfd = accept(sockfd, (struct sockaddr *) &address, &addrlen)) < 0){
			warning(rfd,"accept");
			continue;
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
			http_handler(rfd,_buf, pos);
		}
		// If parent process, close the response socket
		else {
			close(rfd);
		}
	}

	__builtin_unreachable();
}





	
	
	
		
