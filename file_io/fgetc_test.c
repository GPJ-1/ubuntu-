#include<stdio.h>

int main(int argc, char const *argv[])
{
      char * filename="user.txt";
     FILE *ioFile=fopen(filename,"r");
     if(ioFile==NULL)printf("打开失败\n");
    

/*       // return： 读取的一个字节 到文件结尾或出错返回EOF
      char c=fgetc(ioFile);
      while(c!=EOF)
      {
        printf("%c",c);  
        c=fgetc(ioFile);
      }
      printf("\n");  */


      // return: 成功返回字符串 失败返回NULL(可以直接用于while)
  /*     char s[120];
      fgets(s,120,ioFile);
      printf("%s",s);  
      printf("\n");  */
  
      // return: 成功返回参数的个数  失败返回0 报错或结束返回EOF
      char name[50];
      int age;
      char wife[50];
      while(fscanf(ioFile,"%s%d%s\n",name,&age,wife)!=EOF){

        printf("%s在%d岁爱上了%s\n", name, age, wife);
      }
      


     int result=fclose(ioFile);
      if(result==EOF)printf("关闭失败\n");//负数
    return 0;
}
