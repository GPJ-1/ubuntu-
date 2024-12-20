#include<stdio.h>

int main(int argc, char const *argv[])
{
 /*   
   FILE *fopen (const char *__restrict __filename,
		    const char *__restrict __modes) */ 

      char * filename="io.txt";

     FILE *ioFile=fopen(filename,"w");
     if(ioFile==NULL){printf("打开失败\n");}
     else printf("打开成功\n");


// int fclose (FILE *__stream);
     int result=fclose(ioFile);
     if(result==0)printf("关闭成功\n");
     else if(result==EOF)printf("关闭失败\n");//负数
    return 0;


}
