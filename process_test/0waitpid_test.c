#include<stdio.h>//perror的头文件
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>//pid_t

#include <sys/wait.h>//wait


int main(int argc, char const *argv[])
{
    int int_subprocess_status;
    char * name="老学员";
    printf("我是%s,%d我在一楼学习\n",name,getpid());


    pid_t pid =fork();
    if(pid==-1){

        printf("邀请失败");
    }
    else if(pid==0){
        //新学员

        char * new_name="ergou";
        // char  *args[]={"/home/guo/process_test/erlou",new_name,NULL};
        char  *args[]={"/usr/bin/ping","-c","50","www.baidu.com",NULL};
        char *envs[]={NULL};
        execve(args[0],args,envs);
        
    }
    else {
        
        printf("老学员%d邀请完%d之后还是在一楼学习\n",getpid(),pid);
        waitpid(pid,&int_subprocess_status,0);
    }
}