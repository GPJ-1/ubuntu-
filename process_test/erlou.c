#include<stdio.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    if(argc>=2){
        printf("我是%s,进程号是%d,父进程是%d,我跟海哥上二楼了\n",argv[1],getpid(),getppid());
        printf("%s\n",argv[0]);
    }
    else{
        printf("参数不够，上不了二楼\n");
    }
    return 0;
}
