/*************************************************************************
*   <fdupes_command>
*   Copyright (C) 2016  Kushal Purushottam Chandak kpchandak500@gmail.com
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>
**************************************************************************/
#include <stdio.h>
//#include <md5.h>
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
