#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char **arg){
	if(argc==1){
		printf(">>>No file name given\n");
	}
	else if(argc == 2 && strcmp(arg[1],">") && strcmp(arg[1],"-n")){
		FILE* fp=fopen(arg[1],"r");
		if(fp!=NULL){
			char c=fgetc(fp);
			while(c!=EOF){
				printf("%c",c);
				c=fgetc(fp);
			}
			fclose(fp);
		}
		else{
			printf(">>>File Doesn't exist!\n");
		}
	}
	else if(argc ==2 && !strcmp(arg[1],"-E")){

		printf(">>>No file name given!\n");
	}
	else if(argc ==2 && !strcmp(arg[1],"-n")){

		printf(">>>No file name given!\n");
	}
	else if(argc==3 && !strcmp(arg[1],"-n")){
		FILE* fp=fopen(arg[2],"r");
		int line=1;
		char last;
		if(fp!=NULL){
			char c=fgetc(fp);
			if(c!=EOF){
				printf("\t1\t");
				line++;
			}
			while(c!=EOF){
				if(last=='\n'){
					printf("\t%d\t",line);
					line++;
				}
				printf("%c",c);
				last=c;
				c=fgetc(fp);
			}
			fclose(fp);
		}
		else{
			printf(">>>File doesn't exist!\n");
		}
	}
	else if(argc==3 && !strcmp(arg[1],"-E")){
		FILE* fp=fopen(arg[2],"r");
		char last;
		if(fp!=NULL){
			char c=fgetc(fp);
			while(c!=EOF){
				if(c=='\n'){
					printf("$");
				}
				printf("%c",c);
				c=fgetc(fp);
			}
			fclose(fp);
		}
		else{
			printf(">>>File doesn't exist!\n");
		}
	}
	else if(argc==3 && !strcmp(arg[1],">")){
		FILE* fp=fopen(arg[2],"w");
		printf(">>>File created succesfully\n");
		fclose(fp);
	}
	else{
		printf(">>>cat command wrong format");
	}
	return 0;
}
