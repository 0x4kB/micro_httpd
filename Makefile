


micro_httpd: source.c
	gcc -static -nostdlib -Os -nodefaultlibs -nostartfiles -fno-stack-protector -s -O --lto -Wl,--gc-sections,-nostdlib source.c -o micro_httpd

