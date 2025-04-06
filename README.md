
### micro_httpd



A minimalistic http 1.0 webserver, statically linked 3864Bytes.

Capable to serve directory listings and convert markdown files
on the fly via 'lowdown'.


Usage: micro_httpd serverroot

Port 4000 is hardcoded. 

-> http://localhost:4000




To create directory listings and convert markdown files,
/bin/sh needs to be present. (as well as ls, sed and lowdown).



Files are send via 'sendfile', requests are nonpersistent,
the server is forking.


The full source code including assembly routines is in source.c.






2025, misc147, AGPL / CC-BY-SA 4.0

