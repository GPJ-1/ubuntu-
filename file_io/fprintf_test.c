#include<stdio.h>

int main(int argc, char const *argv[])
{


      char * filename="io.txt";
     FILE *ioFile=fopen(filename,"w");
     if(ioFile==NULL){printf("打开失败\n");}
     else printf("打开成功\n");

      // fprintf (FILE *__restrict __stream, const char *__restrict __fmt, ...)
      //成功字符的个数，不包括换行符，失败-1
      char *name="gpj";
      int printfR=fprintf(ioFile,"哎呀,那边窗户透出了什么光?\n那是东方,而你则是太阳!\n升起吧,骄阳,去让忌妒的月黯然失色!\n\t\t%s",name);
     if (printfR==EOF)
     {
      printf("写入失败\n");
     }else{

      printf("写入成功%d",printfR);
     }
     

     int result=fclose(ioFile);
     if(result==0)printf("关闭成功\n");
     else if(result==EOF)printf("关闭失败\n");//负数
    return 0;


}
