#include <sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char **arg){
	int error;
	if(argc==2){
	error=mkdir(arg[1],0777);
	if(error)
		printf(">>>Unable to create directory\n");
	}
	else if(argc==3 && !strcmp(arg[1],"-v"))
	{
		error=mkdir(arg[2],0777);
		if(error)
			printf(">>>Unable to create directory!\n");
		else
			printf("%s created succesfully!\n",arg[2]);
	}
	else if(argc==3 && !strcmp(arg[1],"-p")){
		char* tok=strtok(arg[2],"/");
		char dir[1024];
		while(tok!=NULL){
			strcat(dir,tok);
			strcat(dir,"/");
			//printf("%s\n",dir);
			error=mkdir(dir,0777);
			tok=strtok(NULL,"/");
			if(error)
				printf(">>>Unable to create directory\n");
		}
	}
	else{
		printf(">>>Wrong syntax for mkdir\n");
	}
	return 0;

}
