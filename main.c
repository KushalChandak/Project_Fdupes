/*************************************************************************
*   <fdupes_command>
*   Copyright (C) 2017  Kushal Purushottam Chandak kpchandak500@gmail.com
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
#include<stdio.h>
#include <string.h>
#include<sys/stat.h>
#include "my.h"
int fdupe(char *argv1,char *argv2, int opt){
	int a;
	if(argv1 == NULL || argv2 == NULL)
		return -1;
	int i=sizecmp(argv1,argv2, opt);
	//if size = -1 hence unable to open
	if(i == -1) {
		//printf("Give Valid Input Files\n");
		return -1;
	}
			//size cmp
			if(i==0) {
				char a1[1024],a2[1024];
				//check md5
				calmd5(argv1, a1);
				calmd5(argv2, a2);
								
				int z=strcmp(a1, a2);
				//md5 equal
				if(z == 0) {
				//byte cmpare
				a=bytecmp(argv1, argv2);
					if(a==0){
						//printf("%s\n%s\n\n", argv1, argv2);
						return 0;
						}
					}
				}
				//printf("Files Are Not A Duplicate %s %s\n",argv1, argv2);
				return 1;			
}
	
