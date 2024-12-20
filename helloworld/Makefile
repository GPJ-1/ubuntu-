# Makefile内容通常由以下部分组成
# <目标>: <前置依赖>
#     \t(tab键)<需要执行的命令>

# 放在第一个的是默认目标
# 目标为编译出main文件，依赖main.o和hello.o文件
# 编译的命令为 gcc -o main hello.o main.o
objects:=hello.o main.o



main:$(objects)
	gcc -o main $(objects)

#main.o:main.c hello.h
#	gcc -c main.c 
main.o:hello.h
hello.o:hello.h

#hello.o:hello.c hello.h
#	gcc -c hello.c 


# 声明伪目标
.PHONY: clean


# clean目标可以清理编译的临时文件
clean:
	-rm main $(objects)
# make clean



