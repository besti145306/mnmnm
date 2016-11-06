#include "stdio.h"

void main ()
{
  int i,j;
  int s[16],result[16][16],final_result=0,y,t;
  
 for(i=0;i<16;i++)
  for(j=0;j<16;j++)
    result[i][j]=0;



  printf("input s-box");
  for(i=0;i<16;i++)
  scanf("%d",&s[i]);   //
 
  for(i=0;i<16;i++)
    for(j=0;j<16;j++)
     {
      t = j^i;
      y = s[t]^s[j];
      
     result[i][y]++;
     
     }

for(i=1;i<16;i++)
 for(j=0;j<16;j++)
   {
    if(result[i][j]>final_result)
    final_result=result[i][j];
   }

printf("the result is :%d ",final_result);
   
}
