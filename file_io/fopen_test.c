#include<stdio.h>

int main(int argc, char const *argv[])
{
 /*   
   FILE *fopen (const char *__restrict __filename,
		    const char *__restrict __modes) */ 

      char * filename="io.txt";

     FILE *ioFile=fopen(filename,"w");
     if(ioFile==NULL){printf("打开失败");}
     else printf("打开成功");
    return 0;

}
