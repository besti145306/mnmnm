#include    <stdio.h>
#include    <stdlib.h>
#include    <utmp.h>
#include    <fcntl.h>
#include    <unistd.h>

int show_info( struct utmp *utbufp )
{
    printf("%-8.8s", utbufp->ut_name);  
    printf(" ");                
    printf("%-8.8s", utbufp->ut_line);  
    printf(" ");                
    printf("%10ld", utbufp->ut_time);   
    printf("\n");               
    return 0;
}

int main()
{
    struct utmp  current_record;    
    int     utmpfd;     
    int     reclen = sizeof(current_record);
    //打开utmp 文件
    if ( (utmpfd = open(UTMP_FILE, O_RDONLY)) == -1 ){
        perror( UTMP_FILE );    
        exit(1);
    }

    //读取utmp中的每一条记录
    while ( read(utmpfd, &current_record, reclen) == reclen )
        //显示记录中的相关信息
        show_info(&current_record);
 
    //关闭utmp文件
    close(utmpfd);
    return 0;           
}
