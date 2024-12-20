#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    ssize_t bytes_read;
    int fd=open("io.txt",O_RDONLY);
    if(fd==-1){
        // printf("文件打开失败");
        perror("open");
        exit(EXIT_FAILURE);
    }
    char buffer[1024];//用于存数据
    while((bytes_read=read(fd,buffer,sizeof(buffer)))>0)
    {
        write(STDOUT_FILENO,buffer,bytes_read);
    }
    if(bytes_read==-1){
        printf("读取失败");
        exit(EXIT_FAILURE);
    }
    close(fd);
    return 0;


}
