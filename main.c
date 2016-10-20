#include<stdio.h>
#include <string.h>
#include<sys/stat.h>
#include "my.h"
int main(int argc,char *argv[]){
	int size,a;
	if(argc != 3) {
	printf("No input files\n");
	return 1;
	}
	
	int i=sizecmp(argv[1],argv[2]);
	//if size = -1 hence unable to open
	if(i == -1) {
		printf("Give Valid Input Files\n");
		return 1;	
	}
			//size cmp
			if(i==0) {
				//size equal
				//printf("Size Are Equal\n");
				char a1[128],a2[128];
				//check md5
				calmd5(argv[1], a1);
				calmd5(argv[2], a2);
				int z=strcmp(a1, a2);
				//md5 equal
				if(z==0) {
				//byte cmpare
				a=bytecmp(argv[1], argv[2]);
					if(a==0){
						printf("Files Are Duplicate\n");
						return 0;
						}
					}
				}
				printf("Files Are Not A Duplicate\n");
				return 1;
}
	
