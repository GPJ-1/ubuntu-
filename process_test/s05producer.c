#include <time.h>
#include <mqueue.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *mq_name = "/p_c_mq";

    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 100;
    attr.mq_curmsgs = 0;

    // 创建或打开消息队列
    mqd_t mqdes = mq_open(mq_name, O_CREAT | O_WRONLY, 0666, &attr);

    if (mqdes == (mqd_t)-1)
    {
        perror("mq_open");
    }

    char writeBuf[100];
    struct timespec time_info;

    while (1)
    {
        // 清空写缓冲区
        memset(writeBuf, 0, 100);

        // 从命令行标准输入读取数据
        ssize_t read_count = read(0, writeBuf, 100);
        if (read_count == -1)
        {
            perror("read");
            continue;
        }
        else if (read_count == 0)
        {     // 发送数据
        // 如果接收到命令行的EOF，read将返回0，此时向消费者端发送信息并退出
        // 获取当前时间中5s之后的timespec对象
        clock_gettime(0, &time_info);
        time_info.tv_sec += 5;

            printf("Received EOF, exit...\n");
            char eof = EOF;
            if (mq_timedsend(mqdes, &eof, 1, 0, &time_info) == -1)
            {
                perror("mq_timedsend");
            }
            break;
        }
        // 没有接收到EOF，正常发送数据
        if (mq_timedsend(mqdes, writeBuf, strlen(writeBuf), 0, &time_info) == -1)
        {
            perror("mq_timesend");
        }
        printf("从命令行接收到数据，已发送至消费者端\n");
    }

    // 关闭描述符
    close(mqdes);

    // mq_unlink 只应调用一次，我们选择在消费者中完成此操作

    return 0;
}
