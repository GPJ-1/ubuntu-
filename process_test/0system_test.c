#include<stdio.h>
#include<stdlib.h>


int main(){

    //使用标准库函数创建进程
    /* 
     *   system (const char *__command) __wur;
     *   成功返回0.失败返回对应的编号
     */
    int sysR=system("ping -c 100 www.baidu.com");
    if(sysR!=0){
        perror("system");
    }
    return 0;
}