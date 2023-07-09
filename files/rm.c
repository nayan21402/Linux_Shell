#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char **arg){
	int err;	
	if(argc==1){
		printf(">>>No file name\n");
	}
	else if(argc==2){
		err=unlink(arg[1]);
		if(err){
			printf(">>>File not present.\n");
		}
	}
	else if(argc==3 && !strcmp(arg[1],"-v")){
		err=remove(arg[2]);
		if(err){
			printf(">>>FIle not present.\n");
		}
		else{
			printf(">>>%s deleted succesfully.\n",arg[2]);
		}
	}
	else if(argc==3 && !strcmp(arg[1],"-i")){
		char choice;
		printf(">>>Do you want to delete file %s?(y/n):",arg[2]);
		scanf("%c",&choice);
		if(choice=='y' || choice=='Y')
			err=remove(arg[2]);
		if(err)
			printf(">>>File not present!\n");
	}
	else{
		printf(">>>Invalid syntax\n");
	}
	return 0;
}
