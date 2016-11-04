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
#include <stdlib.h>
#include <string.h>
#include<openssl/md5.h>
//#if defined(__APPLE__)
//#  define COMMON_DIGEST_FOR_OPENSSL
//#  include <CommonCrypto/CommonDigest.h>
//#  define SHA1 CC_SHA1
//#else
//#  include <openssl/md5.h>
//#endif

char *str2md5(const char *str, int length) {
	int n;
	MD5_CTX c;
	unsigned char digest[16];
	char *out = (char*)malloc(33);
	MD5_Init(&c);

	while (length > 0) {
		if (length > 512) {
			MD5_Update(&c, str, 512);
		} 
		else {
			MD5_Update(&c, str, length);
		}
		length -= 512;
		str += 512;
	}

	MD5_Final(digest, &c);

	for (n = 0; n < 16; ++n) {
    		snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
	}

	return out;
} 
