//----------------------gcc.c---------------------------
//readelf -a xxx 目标文件分析工具
//objdump -s 显示目标信息
//nm//List symbols in [file(s)] (a.out by default).
//strip //Removes symbols and sections from files
//lib
1.c/c++编译时，指定程序运行时查找的动态链接库路径
-Wl,-rpath,  用于指定程序运行时查找动态链接库的路径，多个路径是使用冒号隔开。这样就不用添加路径到 /etc/ld.so.conf 文件中了，在需要多个so版本共存时很有用
eg.g++ -Wl,-rpath,/usr/local/lib/ -oevh libevent_http.cpp -levent
2.查看程序链接的动态库
arm-linux-gnueabihf-readelf -d example.so
#error
1.symbol 'E2idE': can't resolve symbol
lib is error
2.malloc
必须在运算之前申请内存
eg:
error:
char *index = malloc();
strcat(index, "d")
char *buf = malloc
correct:
char *index= malloc
char *buf =malloc
strcat();
3.speed_t 数据丢失
一些数据类型不能直接赋值
1.float printf 
must %f
%x is error and change
//---------------------point
unsigned char uu[100];
{&uu[49]}
(char *)(&uu[49])
char *p;
char a;
a=*p;
(int *)p;
(unsigned int *)(&uu[49]);
unsigned int b;
b=*(unsigned int *)(&uu[49]);
unsigned int c;
*(unsigned int *)(&uu[49])=c
//---------------------end-----------------------------
