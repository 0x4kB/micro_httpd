
### micro_httpd



A minimalistic http 1.0 webserver, statically linked 3864Bytes.

Capable to serve directory listings and convert markdown files
on the fly via 'lowdown'.


Usage: micro_httpd serverroot port

micro_https /var/html 4080

-> http://localhost:4080




To create directory listings and convert markdown files,
/bin/sh needs to be present. (as well as ls, sed and lowdown).



Files are send via 'sendfile', requests are nonpersistent,
the server is forking.


The full source code including assembly routines is in source.c.


Files within the serverroot shouldn't contain chars like &,|, and so on. 
Else, this could get problematic with the argument to sh.
This server understands only http get, so. just a warning.

There might be other flaws. Else, this would be more than 4kB.


-----


[https://github.com/kristapsdz/lowdown](https://github.com/kristapsdz/lowdown)


Statically linked binary: 
[https://github.com/michael105/static-bin](https://github.com/michael105/static-bin)




2025, misc147, AGPL / CC-BY-SA 4.0

