#include<stdio.h>

int main(int argc, char const *argv[])
{


      char * filename="io.txt";
     FILE *ioFile=fopen(filename,"w");
     if(ioFile==NULL){printf("打开失败\n");}
     else printf("打开成功\n");

     int put_result=fputc(97,ioFile);
     if (put_result==EOF)
     {
       printf("写入失败\n");
     }else{

         printf("写入%c成功\n",put_result); 
     }
     

     int result=fclose(ioFile);
     if(result==0)printf("关闭成功\n");
     else if(result==EOF)printf("关闭失败\n");//负数
    return 0;


}
