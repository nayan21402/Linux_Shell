#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<pthread.h>
#include<errno.h>
void* pthread_sys(char *argv){
	int err=system(argv);
	if(err)
		printf(">>>system() command failed, error no.:%d\n",err);
}
void pthread(char *argv){
	pthread_t p;
	if(pthread_create(&p,NULL,(void *(*)(void *))pthread_sys,(void *)argv))
		perror(">>>");
	pthread_join(p,NULL);
}

void exc(char **argv){
	pid_t pid=fork();
	if(pid<0){
		perror(">>>");
		exit(1);//exit from child process
	}
	else if(pid==0){
		if(execv(argv[0],argv)<0){
			perror(">>>"); //exit from child process
			exit(1);
		}
	}
	else{
		wait(NULL);
	}
}
int main(){
	int i=0;
	const char *ext_cmd[5];ext_cmd[0]="ls";ext_cmd[1]="cat";ext_cmd[2]="mkdir";
	ext_cmd[3]="date";ext_cmd[4]="rm";
	char root[1024];
	getcwd(root,1024);
	strcat(root,"/");
	char line[1024];
	char delimit[]=" \t\r\n\v\f";
	char dir[1024];
	char dir_hist[1024][1024];
	int hist=0;
	printf(">>>Welcome to SHELL:\n");
	char temp[1024];
	getcwd(temp,1024);	
	strcpy(dir_hist[0],temp);
	int count=0;
	while(1){
	char *arg[64];
	i=0;
	printf(">>>");
	fgets(line,1024,stdin);
	char* rest=line;
	char* token;
	while(token = strtok_r(rest,delimit,&rest)){
			arg[i]=token;
			i++;
		}
	if(i!=0)
	if(!strcmp(arg[0],"pwd") || !strcmp(arg[0],"pwd&t") ){
		char t[1024];
		if(i==1 || (i==2 && !strcmp(arg[1],"-L"))){
			printf("current directory:%s\n",getcwd(dir,1024));
		}
		else if(i==2 && !strcmp(arg[1],"-P")){
			printf(">>>%s\n",getenv("PWD"));
		}
		else{
			printf(">>>Invalid syntax for pwd\n");
		}
	}
	else if(!strcmp(arg[0],"cd") || !strcmp(arg[0],"cd&t") ){
		int flag=0;
		if(i==1 || !strcmp(arg[1],"~")){
			if(chdir(getenv("HOME")))
				perror(">>>");
			}
		 else if(i==2 && !strcmp(arg[1],"-")){
			if(hist<0)
				printf(">>>No more previous visited directory available\n");
			else{
			hist--;
			chdir(dir_hist[hist]);	
			flag=1;		
			}
		}
		else if(i==2){
			if(chdir(arg[1]))
				perror(">>>");
			}	
		if(strcmp(dir_hist[hist],getcwd(dir,1024)) && !flag)
			{	
				hist++;
				strcpy(dir_hist[hist],dir);
			}
						
		}//end of cd
						


	else if(!strcmp(arg[0],"exit")){
		exit(0);
	}
	else if(!strcmp(arg[0],"echo") || !strcmp(arg[0],"echo&t")){
		if(i==1)
			printf(">>>\n");
		else if(i>=2 && !strcmp(arg[1],"-n")){
			printf(">>>");
			for(int j=2;j<i;j++)
				printf("%s ",arg[j]);
		}
		else if(i>=2 && !strcmp(arg[1],"-h")){
			printf(">>>echo prints the text followed by the command\n >>>echo -n prints the text without trailing newline\n");
		}
		else if(i>=2){
			printf(">>>");
			for(int j=1;j<i;j++)
				printf("%s ",arg[j]);
		               
			printf("\n");
		}
		else{
			printf(">>>Invalid syntax for echo\n");
		}
		
	}
	else{
		int flag=0;
		arg[i]=NULL;
		char thread[]="&t";
		char c_thread[3];
		if(strlen(arg[0])>2){
			c_thread[1]=arg[0][strlen(arg[0])-1];
			c_thread[0]=arg[0][strlen(arg[0])-2];
			c_thread[2]='\0';
		}
		char temp[1024];
		strcpy(temp,root);
		if(!strcmp(thread,c_thread)){
			arg[0][strlen(arg[0])-2]='\0';
	
			for(int i=0;i<5;i++){
				printf("%s %s \n",ext_cmd[i],arg[0]);
				if(!strcmp(ext_cmd[i],arg[0]))
					flag=1;}
			
			if(flag){
				strcat(temp,arg[0]);
				arg[0]=temp;
				for(int j=1;j<i;j++){
					strcat(arg[0]," ");
					strcat(arg[0],arg[j]);
					}
				pthread(arg[0]);
				}
			else{
				printf(">>>Enter a valid command!\n");
				}		
		}
		else{
			for(int i=0;i<5;i++)
				if(!strcmp(ext_cmd[i],arg[0]))
					flag=1;
			if(flag){
				strcat(temp,arg[0]);			
				arg[0]=temp;
				exc(arg);
				}
			else{
				printf(">>>Enter a valid command\n");
				}
		}		
		
	}	
	
       }//loop end
	return 0;

}


