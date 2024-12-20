#include <sys/mman.h>//shm
#include <sys/types.h>//pid
#include <sys/wait.h>
#include<fcntl.h>
#include<string.h>//sprintf
#include<unistd.h>//ftruncate
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    //01.创建共享内存对象
    char shmname[100]={0};
    sprintf(shmname,"/letter%d",getpid());
    int fd=shm_open("shmname",O_CREAT|O_RDWR,0664);
    if(fd<0){
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    //02.将该区域扩充为1024字节长度
    ftruncate(fd,1024);
     //03. 以读写方式映射该区域到内存，并开启父子共享标签 偏移量选择0从头开始
    /* 
    * void *addr: 指向期望映射的内存起始地址的指针,通常设为 NULL,让系统选择合适的地址
    * size_t length: 要映射的内存区域的长度,以字节为单位
    * int prot: 内存映射区域的保护标志,可以是以下标志的组合
    *          (1) PROT_READ: 允许读取映射区域
    *          (2) PROT_WRITE: 允许写入映射区域
    *          (3) PROT_EXEC: 允许执行映射区域
    *          (4) PROT_NONE: 页面不可访问
    * int flags：映射选项标志
    *          (1) MAP_SHARED: 映射区域是共享的,对映射区域的修改会影响文件和其他映射到同一区域的进程(一般使用共享)
    *          (2) MAP_PRIVATE: 映射区域是私有的,对映射区域的修改不会影响原始文件,对文件的修改会被暂时保存在一个私有副本中
    *          (3) MAP_ANONYMOUS: 创建一个匿名映射,不与任何文件关联
    *          (4) MAP_FIXED: 强制映射到指定的地址,如果不允许映射,将返回错误
    * int fd: 文件描述符,用于指定要映射的文件或设备,如果是匿名映射,则传入无效的文件描述符（例如-1）
    * off_t offset: 从文件开头的偏移量,映射开始的位置
    * return void*: (1) 成功时,返回映射区域的起始地址,可以像操作普通内存那样使用这个地址进行读写
    *               (2) 如果出错,返回 (void *) -1,并且设置 errno 变量来表示错误原因 
    */

    char *share = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(share==MAP_FAILED){
        perror("mmap");
    }

    close(fd);

    // 04.创建子进程
    pid_t pid = fork(); 
    if (pid == 0)
    {
        // 子进程写入数据作为回信 
        strcpy(share, "你是个好人!\n");
        printf("新学员%d完成回信!\n", getpid());
    }
    else
    {
        int status;
        waitpid(pid,&status,0);// 等待子进程写入
        printf("老学员%d看到新学员%d回信的内容: %s", getpid(),pid,share);
        // 等到子进程运行结束


            // 05.释放映射区
            int ret = munmap(share, 1024); 
            if (ret == -1)
                {
                    perror("munmap");
                    exit(EXIT_FAILURE);
                }
        
    }



 

    //06.释放共享内存对象
    shm_unlink("shmname");
    return 0;
}
