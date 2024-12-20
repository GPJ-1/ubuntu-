//学习sleep()
#include<stdio.h>
#include<sys/types.h>//pid_t
#include<unistd.h>//系统调用的头文件
#include<fcntl.h>//系统调用函数open的头文件
#include<stdlib.h>//exit的头文件
#include<string.h>//strlen strcpy
int main(int argc, char const *argv[])
{

    char buffer[100];
    int fd=open("io.txt",O_CREAT|O_WRONLY|O_APPEND,0644);
    if(fd==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }


    pid_t pid=fork();
    if(pid<0){
        perror("fork");
    }
    else if(pid == 0){
        strcpy(buffer,"子进程写入的数据\n");
    }
    else{
        //父进程
        sleep(1);
        strcpy(buffer,"父进程写入的数据\n");

    }
    //父子进程都要运行的代码

   ssize_t bytes_write=write(fd,buffer,strlen(buffer));
   if (bytes_write==-1){
        perror("write");
   }
   printf("写入成功\n");
   close(fd);
   if(pid==0){
    printf("子进程写入完毕并且释放文件描述符\n");
   }
   else{
    printf("父进程写入完毕并且释放文件描述符\n");
   }



    return 0;
}

