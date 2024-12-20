#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>//open
#include<stdio.h>//perror
#include<unistd.h>


int main(int argc, char const *argv[])
{

    int fd = open("/tmp/myfifo",O_RDONLY);
    if(fd == -1 ){
        perror("open");
    }
    char buffer;
    while (read(fd,&buffer,1)>0){
        write(STDOUT_FILENO,&buffer,1);
    }
    close(fd);
    return 0;
}
