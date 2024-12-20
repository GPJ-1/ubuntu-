#include<stdio.h>
#include<unistd.h>//pipe
#include<stdlib.h>//exit
#include<sys/types.h>//pid_t
#include<string.h>
#include <sys/wait.h>//waitpid
//下面的例子展示了父进程将argv[1]写入匿名管道，子进程读取并输出到控制台

int main(int argc, char const *argv[])
{
    //pipefd: 用于返回指向管道两端的两个文件描述符。pipefd[0]指向管道的读端。pipefd[1]指向管道的写端。
    int pipefd[2];
    char buffer;
    //创建管道
    int repipe=pipe(pipefd);
    if(repipe==-1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid=fork();
    if(pid<0){
       perror("fork"); 
       exit(EXIT_FAILURE);
    }
    if(pid==0){
        printf("我现在是zi进程%d\n",getpid());
        close(pipefd[1]);
        while(read(pipefd[0],&buffer,1)>0){
            write(STDOUT_FILENO,&buffer,1);
        }
        write(STDOUT_FILENO,"\n",1);
        close(pipefd[0]);
        

    }
    else{
        //fu jin cheng
        printf("我现在是fu进程%d\n",getpid());
        close(pipefd[0]);
        write(pipefd[1],argv[1],strlen(argv[1]));
        close(pipefd[1]);
        waitpid(pid,NULL,0); 
     
    }

    return 0;
}
