
### micro_httpd



A minimalistic http 1.0 webserver, linked statically 4kB.

Capable to serve directory listings and convert markdown files
on the fly via 'lowdown'.

Cookie free, optimized for http/1.0

Not intended for the net.


Usage: micro_httpd serverroot [port] [restrict to uid]

micro_http /var/html 4080

-> http://localhost:4080


[port] defaults to 4000
[restrict to uid] is optional, if supplied, only files with that owner uid are served.


To create directory listings and convert markdown files,
/bin/sh needs to be present. (as well as ls, sed and lowdown).
[(lowdown)](https://github.com/kristapsdz/lowdown) / 
[https://github.com/michael105/static-bin](https://github.com/michael105/static-bin)



Files are sent via 'sendfile', requests are nonpersistent,
the server is forking.


The full source code including assembly routines is in source.c.


Files within the serverroot shouldn't contain chars like &,|, and so on. 
Else, this could get problematic with directory listings and the arguments of sh.
This server understands http get only, and tests the paths via a stat
for existence.
So just a notice. Interestingly, I wasn't able to
break that myself. But didn't try too hard.

There might be other weaknesses. Otherwise this would be larger than 4kB.


-----




Statically linked binary for linux 64bit: [amd64/micro_httpd](amd64/micro_httpd) (4kB)




2025 misc147 (www.github.com/michael105), CC-BY-SA 4.0

