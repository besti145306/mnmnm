

#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"

void mian ()
{
  int fd1,fd2;
  
 fd1 = cpen("test1.txt",O_RDONLY,0);
 
  close(fd1);
 fd2 = open("test2.txt",O_RDONLY,0);
 printf("fd2 = %d\n",fd2);

 exit(0);




}
