#include "stdio.h"
#include "func.h"
#define max 10
void main ()
{
   int a[max],array_length;
   printf("how long is the array:");
   scanf("%d",&array_length); 
   printf("input the array:\n");
   
    for(i=0;i<array_length;i++)
     scanf("%d",&a[i]);

  reverse_array(a,array_length);

  for(i=0;i<array_length;i++)
    printf("%d ",a[i]);
     
} 
