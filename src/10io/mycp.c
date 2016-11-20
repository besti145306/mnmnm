#include        <stdio.h>//标准输入输出
#include        <stdlib.h>//C标准函数库
#include        <unistd.h>//Unix类系统定义符号常量
#include        <fcntl.h>//定义了很多宏和open，fcntl函数原型

#define BUFFERSIZE      4096//定义存储器容量
#define COPYMODE        0644//定义复制的长度

void oops(char *, char *);

int main(int argc, char *argv[])
{
    int in_fd, out_fd, n_chars;//三个描述符值
    char buf[BUFFERSIZE];//存储器位置
    
    if (argc != 3) {//检查argc的值是否为三，如果不是，返回标准错误
        fprintf(stderr, "usage: %s source destination\n", *argv);
        exit(1);
    }
    /*检查cp的第一个参数，要复制的文件，用open打开，in_fd为open返回的描述符
    如果返回-1，代表打开失败，提示错误*/
    if ((in_fd = open(argv[1], O_RDONLY)) == -1)
        oops("Cannot open ", argv[1]);

    /*检查cp的第二个参数，复制的目的地址，用create在目的地址创建新文件，out_fd为open返回的描述符
    如果返回-1，代表创建失败，提示错误*/
    if ((out_fd = creat(argv[2], COPYMODE)) == -1)
        oops("Cannot creat", argv[2]);

    /*cp指令的动作就是读取一个文件的内容到存储器，在新的地址创建空白文件，再从存储器将内容写入新文件。
    这里判断复制是否成功：
    如果能读取顺利，而读取的位数和写的位数不同，是写错误；
    如果读取失败，是读错误。*/
    while ((n_chars = read(in_fd, buf, BUFFERSIZE)) > 0)
        if (write(out_fd, buf, n_chars) != n_chars)
            oops("Write error to ", argv[2]);
    if (n_chars == -1)
        oops("Read error from ", argv[1]);

    /*这里执行的是关闭文件的动作，in_fd和out_fd两个文件描述符
    所指向的文件只要有一个关闭错误，就提示关闭错误。*/
    if (close(in_fd) == -1 || close(out_fd) == -1)
        oops("Error closing files", "");
}

/*这个是用来输出错误信息的函数*/
void oops(char *s1, char *s2)
{
    fprintf(stderr, "Error: %s ", s1);
    perror(s2);//用来将上一个函数发生错误的原因输出到标准设备(stderr)
    exit(1);
}
