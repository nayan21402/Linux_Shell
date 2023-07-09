#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char **arg){
	DIR *dir;
	struct dirent **dp;
	int num=0;
	char d[1024];
	getcwd(d,1024);

	num= scandir(d,&dp,NULL,alphasort);
	if(num==-1){
		printf("No such directory");
		return 1;
	}
	printf(">>>");
	if(arg[1]==NULL){
		for(int i=0;i<num;i++){
			char temp=dp[i]->d_name[0];
			if(temp!='.')
			printf("%s ",dp[i]->d_name);
			free(dp[i]);
		}
		free(dp);
	}
	else if(strcmp(arg[1],"-r")==0 && argc==2){
		for(int i=num-1;i>=0;i--){
			char temp=dp[i]->d_name[0];
			if(temp!='.')
			printf("%s ",dp[i]->d_name);
			free(dp[i]);
		}
		free(dp);
	}
	else if(strcmp(arg[1],"-a")==0 && argc==2){
		for(int i=0;i<num;i++){
			printf("%s ",dp[i]->d_name);
			free(dp[i]);
		}
		free(dp);
	}
	else{
		printf(">>>Wrong syntax for ls\n");
	}
	printf("\n");
	return 0;
}
