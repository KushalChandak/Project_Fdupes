#include<stdio.h>
#include<sys/stat.h>
int bytecmp(char *argv1, char*argv2) {
	FILE *fp;
	FILE *fp1;
	fp=fopen(argv1,"r");
	fp1=fopen(argv2,"r");
	int x, y;
	while((x=fgetc(fp))!=EOF && (y=fgetc(fp1))!=EOF){
			//	printf("%c \t %c \n",x,y);
	if(x!=y){
			//printf("Not A Duplicate\n");
			return 1;
		}
		
	}
	return 0;

}


