#include <stdio.h>
#include <openssl/md5.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"
#include <openssl/hmac.h>

void calmd5(char *argv1, char* a){
	unsigned char c[MD5_DIGEST_LENGTH];
	//file *file=fopen(argv[1],"r")
    	//char *filename;
	int i;
	FILE *inFile = fopen (argv1, "rb");
	MD5_CTX mdContext;
	int bytes;
	unsigned char data[1024];
	if (inFile == NULL) {
		printf ("%s can't be opened.\n", argv1);
		return ;
	}

	MD5_Init (&mdContext);	
	while ((bytes = fread (data, 1, 1024, inFile)) != 0)
		MD5_Update (&mdContext, data, bytes);
	MD5_Final (c,&mdContext);
	//for(i = 0; i < MD5_DIGEST_LENGTH; i++)
	//printf("%02x", c[i]);
	//printf ("\n");
	fclose (inFile);
	strcpy(a,c);
}
