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
#include <dirent.h> 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int fdupe(char *d,char *d1, int opt);
void print(int end, int isCalSize);
char **output;
char directory[128];
char **filename;
void initfilesrec(const char *name, int *count) {
	DIR *d;
    struct dirent *dir;
   
    if (!(d = opendir(name))){
    	printf("find : '%s' :\n", name);
        return;
    }
    if (!(dir = readdir(d))){
    	printf("%s\n", "error");
        return;
    }
    //printf("%s\n",name);
    /*if(strcmp(name,"./") == 0)	
	strcpy((char *)name,".");*/
	do {
		if (dir->d_type == DT_DIR) {
		    char path[1024];
		    snprintf(path, sizeof(path), "%s%s/", name, dir->d_name);
		    if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
		        continue;
		    initfilesrec(path, count);
		}
		else {
		    //printf("%s%s\n",name, dir->d_name);
		    	filename[(*count)] = (char *)malloc(sizeof(char) * ((strlen(dir->d_name) + 1) + strlen(name)));
			strcpy(filename[(*count)], name);
			strcat(filename[(*count)], dir->d_name);
		 	(*count)++;
		}
	    } while ((dir = readdir(d)));
    closedir(d);
}

int main(int argc, char *argv[]){
	DIR *d;
	output = (char **) malloc(sizeof(char *) * 128 * 128 * 128 * 128);
	int i = 0, j, ocount = 0, r, opt = 0, isCalSize = 0;
	filename = (char **) malloc(sizeof(char *) * 128 * 128 * 128);
	struct dirent *dir;
	if(argc == 4) {
		//invalid
		return -1;
	}
	if(argc == 1) {
		printf("%s: no directories specified\n", argv[0]);
		return 1;
	}
	
	if(argc == 2 && (strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"--help") == 0)){
		FILE *fp;
		char c, *s="help.txt";
		fp = fopen(s,"r");
		if(fp == NULL){
			printf("can't open file");
		exit(0);
		}
		c=fgetc(fp);
		while(c != EOF){
			printf("%c",c);
			c=fgetc(fp);
		}
		fclose(fp);
		return 0;		
	}
	
	/* this codes sets the directory */
	if(argc == 2) {
		if((strcmp(argv[1], ".") == 0) || (strcmp(argv[1], "./") == 0)) {
			strcpy(directory, argv[1]);
			if(directory[strlen(directory) - 1] != '/')
				strcat(directory, "/");
			i = 0;
			/*  creates list of all files to be scanned */
		
			d = opendir(directory);
			if(d == NULL) {
				printf("%s: could not chdir to %s\n", argv[0], argv[argc - 1]);
				return 1;
			}
			if (d) {
				while ((dir = readdir(d)) != NULL){
					if (dir->d_type == DT_REG){
						//printf("\t%s\n", dir->d_name);
						filename[i] = (char *)malloc(sizeof(char) * ((strlen(dir->d_name) + 1) + strlen(directory)));
						strcpy(filename[i], directory);
						strcat(filename[i++], dir->d_name);
					}
				}
		    	closedir(d);
		    	}
		    }
		    else {
		    	printf("%s: could not chdir to %s\n", argv[0], argv[1]);
		    	return -1;
		    }
		    	
	}
	/* end */
	else if(argc == 3 && (strcmp(argv[1], "-n") == 0)) {
		opt = 1;
		/* this codes sets the directory */
		strcpy(directory, argv[2]);
		if(directory[strlen(directory) - 1] != '/')
			strcat(directory, "/");
		/* end */
		i = 0;
		/* this codes sets the directory */
		strcpy(directory, argv[2]);
		if(directory[strlen(directory) - 1] != '/')
			strcat(directory, "/");
		/* end */
		/*  creates list of all files to be scanned */
		
		d = opendir(directory);
		if(d == NULL) {
			printf("%s: could not chdir to %s\n", argv[0], argv[argc - 1]);
			return 1;
		}
		if (d) {
			while ((dir = readdir(d)) != NULL){
				if (dir->d_type == DT_REG){
					//printf("\t%s\n", dir->d_name);
					filename[i] = (char *)malloc(sizeof(char) * ((strlen(dir->d_name) + 1) + strlen(directory)));
					strcpy(filename[i], directory);
					strcat(filename[i++], dir->d_name);
				}
			}
	    	closedir(d);
	    	}
	    	/* end */
	}
	else if(argc == 3 && (strcmp(argv[1], "-S") == 0)) {
		isCalSize = 1;
		/* this codes sets the directory */
		strcpy(directory, argv[2]);
		if(directory[strlen(directory) - 1] != '/')
			strcat(directory, "/");
		/* end */
		i = 0;
		/* this codes sets the directory */
		strcpy(directory, argv[2]);
		if(directory[strlen(directory) - 1] != '/')
			strcat(directory, "/");
		/* end */
		/*  creates list of all files to be scanned */
		
		d = opendir(directory);
		if(d == NULL) {
			printf("%s: could not chdir to %s\n", argv[0], argv[argc - 1]);
			return 1;
		}
		if (d) {
			while ((dir = readdir(d)) != NULL){
				if (dir->d_type == DT_REG){
					//printf("\t%s\n", dir->d_name);
					filename[i] = (char *)malloc(sizeof(char) * ((strlen(dir->d_name) + 1) + strlen(directory)));
					strcpy(filename[i], directory);
					strcat(filename[i++], dir->d_name);
				}
			}
	    	closedir(d);
	    	}
	    	/* end */
	}
	else if(argc == 3 && (strcmp(argv[1], "-m") == 0)) {
		isCalSize = 2;
		/* this codes sets the directory */
		strcpy(directory, argv[2]);
		if(directory[strlen(directory) - 1] != '/')
			strcat(directory, "/");
		/* end */
		i = 0;
		/* this codes sets the directory */
		strcpy(directory, argv[2]);
		if(directory[strlen(directory) - 1] != '/')
			strcat(directory, "/");
		/* end */
		/*  creates list of all files to be scanned */
		
		d = opendir(directory);
		if(d == NULL) {
			printf("%s: could not chdir to %s\n", argv[0], argv[argc - 1]);
			return 1;
		}
		if (d) {
			while ((dir = readdir(d)) != NULL){
				if (dir->d_type == DT_REG){
					//printf("\t%s\n", dir->d_name);
					filename[i] = (char *)malloc(sizeof(char) * ((strlen(dir->d_name) + 1) + strlen(directory)));
					strcpy(filename[i], directory);
					strcat(filename[i++], dir->d_name);
				}
			}
	    	closedir(d);
	    	}
	    	/* end */
	}
	else if(argc == 3 && (strcmp(argv[1], "-r") == 0)) {
		i = 0;
		/* this codes sets the directory */
		strcpy(directory, argv[2]);
		if(directory[strlen(directory) - 1] != '/')
			strcat(directory, "/");
		/* end */
		initfilesrec(directory, &i);
	}
	else {
		/*i = 0;
		/* this codes sets the directory 
		strcpy(directory, argv[2]);
		if(directory[strlen(directory) - 1] != '/')
			strcat(directory, "/");
		/* end */
		/*  creates list of all files to be scanned 
		
		d = opendir(directory);
		if(d == NULL) {
			printf("%s: could not chdir to %s\n", argv[0], argv[argc - 1]);
			return 1;
		}
		if (d) {
			while ((dir = readdir(d)) != NULL){
				if (dir->d_type == DT_REG){
					//printf("\t%s\n", dir->d_name);
					filename[i] = (char *)malloc(sizeof(char) * ((strlen(dir->d_name) + 1) + strlen(directory)));
					strcpy(filename[i], directory);
					strcat(filename[i++], dir->d_name);
				}
			}
	    	closedir(d);
	    	}*/
	    	/* end */
	    	printf("%s: Invalid options --'%s'\n", argv[0], argv[1]);
	    	printf("Try `%s --help' for more information.\n", argv[0]);
	    	return -1;
    	}
    	int n = i;
    	for(i = 0; i < n; i++) {
    		for(j = i + 1; j < n; j++) {
    			//printf("\t%s %s\n", filename[i], filename[j]);
    			r = fdupe(filename[i], filename[j], opt);
    			//printf("%d\n", r);
    			if(r == 0) {
    				output[ocount] = (char *) malloc(sizeof(char) * (strlen(filename[i]) + 1));
    				strcpy(output[ocount++], filename[i]);
    				output[ocount] = (char *) malloc(sizeof(char) * (strlen(filename[j]) + 1));
    				strcpy(output[ocount++], filename[j]);
    				//printf("%s\n%s\n\n", filename[i], filename[j]);
    			}
    		}
    	
    	}
   	
    	print(ocount, isCalSize);
    	free(filename);
    	free(output);
 	return 0;
}

void deleteall(char *s, int start, int end) {
	if(start >= end)
		return;
	//printf("   %s %s\n", s, output[start]);
	deleteall(s, start + 1, end);
	if(strcmp(output[start], s) == 0) {
		strcpy(output[start], "");
	}
}

int kk = 0;
int dntprint = 0;
long extrasize = 0;

void printchild(char *s, int start, int end) {
	if(start >= end - 2) {
		return;	
	}
	printchild(s, start + 2, end);
	if(strcmp(output[start], s) == 0) {
		//printf("\t%d %s->%s->%s\n",start, s, output[start], output[start + 1]);
		if(!dntprint)
			printf("%s\n", output[start + 1]);
		else {
			kk++;
			/* calculate extra size */
			FILE *fp = fopen(output[start + 1], "r");
			fseek(fp, 0, 2);
			extrasize += ftell(fp);
			fclose(fp);
		}
		//strcpy(output[start], "");
		deleteall(output[start], start, end);
		deleteall(output[start + 1], start + 1, end);
		//strcpy(output[start + 1], "");
	}
}

void print(int end, int isCalSize) {
	int sets = 0, files = 0;
	long size = 0;
	for(int i = 0; i < end ; i+= 2) {
		if((strcmp(output[i], "") == 0) || (strcmp(output[i + 1], "") == 0))
			continue;
		if(isCalSize == 1) { 
			long size;
			FILE *fp = fopen(output[i], "r");
			fseek(fp, 0, 2);
			size = ftell(fp);
			fclose(fp);
			printf("%ld bytes each:\n", size);
			printf("%s\n", output[i]);
			printf("%s\n", output[i + 1]);
			printchild(output[i], i + 2, end);
			printf("\n");
		}
		else if(isCalSize == 2) {
			//size = 0;
			FILE *fp = fopen(output[i], "r");
			fseek(fp, 0, 2);
			size += ftell(fp);
			fclose(fp);
			//printf("%ld bytes each:\n", size);
			//printf("%s\n", output[i]);
				sets++;
			//printf("%s\n", output[i + 1]);
				files++;
				dntprint = 1;
			printchild(output[i], i + 2, end);
		}
		else {
			printf("%s\n", output[i]);
			printf("%s\n", output[i + 1]);
			printchild(output[i], i + 2, end);
			printf("\n");
		}
	}
	if(isCalSize == 2) {
		int depth = 0;
		long double filesize =(long double) size + extrasize;
		while(filesize > 1000) {
			filesize = filesize / 1000;
			depth++;
		}
		printf("%d duplicate files (in %d sets), occupying %.1Lf ", files + kk, sets, filesize);
		switch(depth) {
			case 0: 
				printf("bytes\n\n");
				break;
			case 1:
				printf("kylobytes\n\n");
				break;
			case 2:
				printf("megabytes\n\n");
				break;
			case 3:
				printf("gigabytes\n\n");
		}
	}
}
