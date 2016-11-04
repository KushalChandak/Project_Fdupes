project: dir.c md5.c sizecmp.c bytecmp.c main.c
	cc -g -fno-stack-protector dir.c bytecmp.c md5.c main.c sizecmp.c -lssl -lcrypto -o project
dir.o: dir.c
	cc -c dir.c
md5.o: md5.c md5.h
	cc -c md5.c -lcrypto -lssl
main.o: main.c
	cc -c main.c
sizecmp.o: sizecmp.c
	cc -c sizecmp.c
bytecmp.o: bytecmp.c
	cc -c bytecmp.c
