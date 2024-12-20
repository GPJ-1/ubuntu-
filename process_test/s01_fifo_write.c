#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>//open
#include<stdio.h>//perror
#include<string.h>
#include<unistd.h>
#include<errno.h>//errno

int main(int argc, char const *argv[])
{
    int refifo=mkfifo("/tmp/myfifo",0664);
    if(refifo!=0){
        perror("mkfifo");
         if (errno != 17)
        {
            exit(EXIT_FAILURE);
        }
    }

    int fd = open("/tmp/myfifo",O_WRONLY);
    if(fd == -1 ){
        perror("open");
    }
    char buffer;
    printf("请输入\n");
    while(read(STDIN_FILENO,&buffer,1)>0){
        write(fd,&buffer,1);
    }

    printf("发送管道退出，进程终止\n");
    close(fd);
    //释放管道
    unlink("/tmp/myfifo");
    return 0;
}
