#include "stdio.h"

void main ()

{
    int total=0;
    int i,in;

    printf("in:");
    scanf("%d",&in);

    for(i=0;i<in;i++)
        total = total + i;


    printf("  %d  ",total);


}
