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

#if __BYTEORDER == __LITTLE_ENDIAN
#define HTONS16(_x) ( ((_x&0xff) <<8)|((_x>>8)&0xff) )
#else
#define HTONS16(_x) (_x)
#endif


// format: enum,enum, 'index'[' '"typename"'\0']"extension\0" ...
// typename is also scanned as extension
#ifndef BLOAT
#define _MIMETYPES \
  _MIME ( UNKNOWN, unknown,  "\1 octet-stream" ) \
  _MIME ( avi, video_avi,  "\5.avi" ) \
  _MIME ( bmp, image_bmp,  "\4.bmp" ) \
  _MIME ( c, text_x_c,  "\6 x-c\0.c\0.h" ) \
  _MIME ( css, text_css,  "\6.css" ) \
  _MIME ( csv, text_csv, "\6.csv" )  /* Comma-separated values (CSV) */ \
  _MIME ( gif, image_gif,  "\4.gif" ) \
  _MIME ( gz, 	application_gz,  "\1.gz" ) \
  _MIME ( html, text_html,  "\6.html\0.shtml\0.htm\0.php" ) \
  _MIME ( ico, image_x_icon, "\4 x-icon\0.ico" )  /* Icon format */ \
  _MIME ( jar, application_java_archive, "\1 java-archive\0.jar" )  /* Java Archive (JAR) */ \
  _MIME ( javascript, application_x_javascript,  "\1 x-javascript\0.js" ) \
  _MIME ( jpeg, image_jpeg,  "\4.jpeg\0.jpg" ) \
  _MIME ( json, application_json, "\1.json" )  /* JSON format */ \
  _MIME ( markdown, text_markdown,  "\6.markdown\0.md" ) \
  _MIME ( mp3, audio_mpeg3, "\3.mpeg3\0.mp3" ) \
  _MIME ( mpg, video_mpeg,  "\5.mpeg\0.mpg" ) \
  _MIME ( msword, application_msword,  "\1 msword\0.doc" ) \
  _MIME ( octet_stream, application_octet_stream,  "\1 octet-stream\0.bin\0.rar" ) \
  _MIME ( pdf, application_pdf,  "\1.pdf" ) \
  _MIME ( plain, text_plain,  "\6 plain\0README\0.nfo\0.txt" ) \
  _MIME ( png, image_png,  "\4.png" ) \
  _MIME ( sh, application_x_sh, "\1 x-sh\0.sh" )  /* Bourne shell script */ \
  _MIME ( tar, application_x_tar, "\1 x-tar\0.tar" )  /* Tape Archive (TAR) */ \
  _MIME ( tiff, image_tiff,  "\4.tiff" ) \
  _MIME ( ttf, font_ttf, "\7.ttf\0.tif" )  /* TrueType Font */ \
  _MIME ( webp, image_webp, "\4.webp" )  /* WEBP image */ \
  _MIME ( xhtml, application_xhtml_xml, "\1 xhtml+xml\0.xhtml" )  /* XHTML */ \
  _MIME ( xml, application_xml,  "\1.xml" ) \
  _MIME ( zip, application_zip,  "\1.zip" ) \


#else

#define _MIMETYPES \
  _MIME ( UNKNOWN, unknown,  "\1 octet-stream" ) \
   _MIME( aac, audio_aac, "\3.aac" )  /* AAC audio file */ \
   _MIME( abw, application_x_abiword, "\1 x-abiword\0.abw" )  /* AbiWord document */ \
   _MIME( arc, application_octet_stream, "\1.arc\0.bin" )  /* Archive document, any kind*/ \
   _MIME( avi, video_x_msvideo, "\5 x-ms_video\0.avi" )  /* AVI: Audio Video Interleave */ \
   _MIME( azw, application_vnd_amazon_ebook, "\1 vnd.amazon.ebook\0.azw" )  /* Amazon Kindle eBook format */ \
  _MIME ( bmp, image_bmp,  "\4.bmp" ) \
   _MIME( bz, application_x_bzip, "\1 x-bzip\0.bz" )  /* BZip archive */ \
   _MIME( bz2, application_x_bzip2, "\1 x-bzip2\0.bz2" )  /* BZip2 archive */ \
   _MIME( csh, application_x_csh, "\1 x-csh\0.csh" )  /* C-Shell script */ \
   _MIME( css, text_css, "\6.css" )  /* Cascading Style Sheets (CSS) */ \
   _MIME( csv, text_csv, "\6.csv" )  /* Comma-separated values (CSV) */ \
   _MIME( doc, application_msword, "\1 msword\0.doc" )  /* Microsoft Word */ \
   _MIME( epub, application_epub_zip, "\1.epub" )  /* Electronic publication (EPUB) */ \
   _MIME( gif, image_gif, "\4.gif" )  /* Graphics Interchange Format (GIF) */ \
   _MIME( html, text_html, "\6.html\0htm" )  /* HyperText Markup Language (HTML) */ \
   _MIME( ico, image_x_icon, "\4 x-icon\0.ico" )  /* Icon format */ \
   _MIME( ics, text_calendar, "\6.calendar\0.ics" )  /* iCalendar format */ \
   _MIME( jar, application_java_archive, "\1 java-archive\0.jar" )  /* Java Archive (JAR) */ \
   _MIME( jpg, image_jpeg, "\4.jpeg\0.jpg" )  /* JPEG images */ \
   _MIME( js, application_javascript, "\1 javascript\0.js" )  /* JavaScript (ECMAScript) */ \
   _MIME( json, application_json, "\1.json" )  /* JSON format */ \
  _MIME ( markdown, text_markdown,  "\6.markdown\0.md" ) \
   _MIME( midi, audio_midi, "\3.midi\0.mid" )  /* Musical Instrument Digital Interface (MIDI) */ \
   _MIME( mpeg, video_mpeg, "\5.mpeg" )  /* MPEG Video */ \
   _MIME( oga, audio_ogg, "\3.ogg\0.ogx\0oga" )  /* OGG audio */ \
   _MIME( ogv, video_ogg, "\5 ogg.ogv" )  /* OGG video */ \
   _MIME( pdf, application_pdf, "\1.pdf" )  /* Adobe Portable Document Format (PDF) */ \
   _MIME( rar, application_x_rar_compressed, "\1 x-rar\0.rar" )  /* RAR archive */ \
   _MIME( rtf, application_rtf, "\1.rtf" )  /* Rich Text Format (RTF) */ \
   _MIME( sh, application_x_sh, "\1 x-sh\0.sh" )  /* Bourne shell script */ \
   _MIME( svg, image_svg_xml, "\4svg+xml\0.svg" )  /* Scalable Vector Graphics (SVG) */ \
   _MIME( swf, application_x_shockwave_flash, "\1 x-shockwave-flash\0.swf" )  /* Small web format (SWF) or Adobe Flash document */ \
   _MIME( tar, application_x_tar, "\1 x-tar\0.tar" )  /* Tape Archive (TAR) */ \
   _MIME( ttf, font_ttf, "\7.ttf\0.tif" )  /* TrueType Font */ \
   _MIME( wav, audio_x_wav, "\3 x-wav\0.wav" )  /* Waveform Audio Format */ \
   _MIME( weba, audio_webm, "\3.weba" )  /* WEBM audio */ \
   _MIME( webm, video_webm, "\5.webm" )  /* WEBM video */ \
   _MIME( webp, image_webp, "\4.webp" )  /* WEBP image */ \
   _MIME( woff, font_woff, "\7.woff" )  /* Web Open Font Format (WOFF) */ \
   _MIME( woff2, font_woff2, "\7.woff2" )  /* Web Open Font Format (WOFF) */ \
   _MIME( xhtml, application_xhtml_xml, "\1 xhtml+xml\0.xhtml" )  /* XHTML */ \
   _MIME( xls, application_vnd_ms_excel, "\1 vnd.ms-excel\0.xls" )  /* Microsoft Excel */ \
   _MIME( xml, application_xml, "\1.xml" )  /* XML */ \
   _MIME( xul, application_vnd_mozilla_xul_xml, "\1 vnd.mozilla.xul+xml\0.xul" )  /* XUL */ \
   _MIME( zip, application_zip, "\1.zip" )  /* ZIP archive */ \
   _MIME( vid3gp, video_3gpp, "\5.3gp" )  /* 3GPP audio/video container */ \
   _MIME( vid3g2, video_3gpp2, "\5.3g2" )  /* 3GPP2 audio/video container */ \
   _MIME( app7z, application_x_7z_compressed, "\1 x-7z-compressed\0.7z" )  /* 7-zip archive */ 

//   _MIME( odp, application_vnd.oasis.opendocument.presentation, "\1.odp" )  /* OpenDocuemnt presentation document */ \
//   _MIME( ods, application_vnd.oasis.opendocument.spreadsheet, "\1.ods" )  /* OpenDocuemnt spreadsheet document */ \
//   _MIME( odt, application_vnd.oasis.opendocument.text, "\1.odt" )  /* OpenDocument text document */ \

#endif

const char* mimeclass_str =
        "application\0audio\0image\0video\0text\0\0font";
		  // 1         3      4      5      6        7
// pos: (index-1) * 6

#define _MIME(_s,_e,_ext) _ext,
const char * const mimetypes_ext[] ={
	_MIMETYPES
};
#undef _MIME

#define _MIME(_s,_e,_ext) (char)(sizeof(_ext)-1),
const char mimetypes_ext_len[] ={
	_MIMETYPES
};
#undef _MIME

#define _MIME(_s,_e,_ext) _s,_e=_s,
#define _MIME_ENUM enum { _MIMETYPES ENDENUM }

// return enum value of _mime ( png, image_png, markdown, text_markdown, .. )
#define MIMETYPE(_type) ({ _MIME_ENUM; _type; })

// return a pointer to a mimetype str (no check of bounds)
#define MIMESTR(_mimetype) ({ _MIME_ENUM; char buf[32]; mimetype_str( buf, _mimetype); buf; })


// copy the mimetype str into buf
static char* mimetype_str( char* buf, int mimetype ){
	int index = *mimetypes_ext[mimetype];	

	char *p = stpcpy(buf,mimeclass_str+(index-1)*6);
	*p++ = '/';

	stpcpy( p, (mimetypes_ext[mimetype] +2) );

	return(buf);
}



// return the mimetype number
static int getmimetype(const char* path){
	const char *pend = path + strlen(path) - 1;

	int type = 0;
	for ( const char *const *m = mimetypes_ext; m - mimetypes_ext < sizeof(mimetypes_ext)/sizeof(char*); m++ ){
		const char *p, *pext=*m;
		pext += mimetypes_ext_len[m - mimetypes_ext]; // point at the end
																
		do {
			p = pend;
			pext--;
			while ( *p && (tolower(*p)==*pext) ){
				 p--; pext--;
			}
			if ( *pext < 040 ){ // match
				//printvl( "mstr: ",({ char buf[32]; mimetype_str( buf, m - mimetypes_ext); buf; }) );
				return( m - mimetypes_ext );
			}
			while ( *pext > 037 ){
				pext--;
			}

		} while ( *pext == 0 ); // > 0 = last
	}

	return(MIMETYPE(unknown));
}





static void sendheader( char*status, char*title, int mimetype ){
	prints( "HTTP/1.0 ", status, " ",title, "\r\n"
			"Server: micro_httpd " VERSION ".misc147\r\n" 
			"Connection: close\r\n"
			"Allow: GET\r\n"
			"Content-Type: ",MIMESTR(mimetype),"\r\n\r\n"
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

	if ( argc < 2 || argv[1][0] == '-' ){
		ewrites("Usage: microserve pathname [port]\n");
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
	int port = 0;
	if ( argc>2 )
		for ( const char *p = argv[2]; *p>='0' && *p<='9'; p++ )
			port = port*10 + *p-'0';

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





	
	
	
		
