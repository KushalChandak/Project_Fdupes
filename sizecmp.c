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
#include <stdio.h>
#include<sys/stat.h>
int sizecmp(char* argv1, char *argv2, int opt) {
	FILE *fp;
	FILE *fp1;    
	int size = 0;
	int size1=0;
	fp = fopen(argv1, "r");
	fp1=fopen(argv2, "r");
   	if(!fp || !fp1) {
   		 
		return -1;
	}
   	else {
		fseek(fp, 0, 2);    
		size = ftell(fp);   
		fseek(fp1,0,2);
		size1=ftell(fp1);   
		fclose(fp);
		fclose(fp1);
		if(size==size1) {
			if(size == 0 && opt == 1)
				return 1;
			return 0;
		}
	}
	return 1;
} 
