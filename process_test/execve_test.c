#include<stdio.h>//perror的头文件
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char const *argv[])
{
    char *name="juge";
    printf("我是%s,我的进程号%d,父进程号是%d,我现在在一楼\n",name,getpid(),getppid());

    /* 
     char *__path:执行程序的路径
     char *const __argv[]: 指向字符串数组的指针 需要传入多个参数
        (1) 需要执行的程序命令(同*__path)
        (2) 执行程序需要传入的参数
        (3) 最后一个参数必须是NULL
     char *const __envp[]: 指向字符串数组的指针 需要传入多个环境变量参数
        (1) 环境变量参数 固定格式 key=value
        (2) 最后一个参数必须是NULL

     */
    char* args[]={"/home/guo/process_test/erlou",name,NULL};
    char* envs[]={NULL};

    execve(args[0],args,envs);

    //正常情况下这里是执行不到的
    perror("execve");
    return 0;
}
