#include <stdio.h>
#include<sys/stat.h>
int sizecmp(char* argv1, char *argv2){
	FILE *fp;
	FILE *fp1;    
	//char ch;
	int size = 0;
	int size1=0;
	fp = fopen(argv1, "r");
	fp1=fopen(argv2, "r");
   	if(!fp || !fp1) {
   		 //printf("\nFile unable to open ");
		return -1;
	}
   	else {
		//printf("\nFile opened \n");
	}
	fseek(fp, 0, 2);    
	size = ftell(fp);   
	//  printf("The size of given file is : %d\n", size);
	fseek(fp1,0,2);
	size1=ftell(fp1);
	//  printf("The size of given file is : %d\n", size1);    
	fclose(fp);
	fclose(fp1);
	if(size==size1) {
		// printf("files are equal\n");
		return 0;
	}
	else
		return 1;
   		// printf("files are not equal\n");
} 
