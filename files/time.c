#include <stdio.h>
#include <time.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc, char **arg){
	time_t t= time(NULL);
	struct tm *tm = localtime(&t);
	char time[1024];
	if(argc==1){
		strftime(time,1024,"%a %b %d %r %Z %G",tm);
		printf(">>>%s\n",time);
	}
	else if(argc==2 && !strcmp(arg[1],"-u")){
		tm=gmtime(&t);
		strftime(time,1024,"%a %b %d %r UTC %G",tm);
		printf(">>>%s\n",time);
	}
	else if(argc==3 && !strcmp(arg[1],"-r")){
		struct stat file;
		char dir[1024];
		getcwd(dir,1024);
		strcat(dir,"/");
		strcat(dir,arg[2]);
		if(!stat(dir,&file)){
			strftime(time,1024,"%a %b %d %r %Z %G",localtime(&file.st_mtime));
			printf("%s\n",time);
		}
		else{
			printf(">>>File does't exist!\n");
		}
	}
	else{
		printf(">>>Wrong format for date\n");
	}
	return 0;
}
