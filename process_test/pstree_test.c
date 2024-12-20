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
        char  *args[]={"/home/guo/process_test/erlou",new_name,NULL};
        char *envs[]={NULL};
        //挂起子进程使它成为孤儿进程
        // sleep(10);
        execve(args[0],args,envs);
        
    }
    else {
        
        printf("老学员%d邀请完%d之后还是在一楼学习\n",getpid(),pid);
        //挂起父进程
       // fgetc(stdin);
    }

    // return 0;
}