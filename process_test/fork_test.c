#include<stdio.h>
#include<sys/types.h>//pid_t
#include<unistd.h>//系统调用的头文件


int main(){
    //调用fork之前，代码都在父进程中运行
    printf("老学员的进程号%d\n",getpid());


    //从fork之后所有的代码，在父子进程中各执行一次
    //先执行父进程的代码
    pid_t pid= fork();
    

    if(pid<0){
        printf("新学员邀请失败");
        return 1;
    }
    else if(pid==0){
        //执行新进程的代码
        printf("新学员的进程号%d\n",getpid());
        printf("老学员的进程号%d\n",getppid());
    }
    else{

        //执行老学员的代码
        printf("老学员的进程号%d\n",getpid());
        printf("新学员的进程号%d\n",pid);

    }

    return 0;
}