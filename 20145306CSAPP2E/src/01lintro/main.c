#include "stdio.h"
#include "head.h"

void main ()
{

   int a,b,c,r;
   double f;


   printf("input a,b:");
   scanf("%d",&a); 
   scanf("%d",&b);

   printf("1:add 2:subtract 3:multiply 4 divide");
   scanf("%d",&c);
   switch(c)
   {
      case 1:
      r= add(a,b);
      printf("%d",r);
      break;
     
      case 2:
      r= subtract(a,b);
      printf("%d",r);
      break;  

      case 3:
      r= multiply(a,b);
      printf("%d",r); 
     break;

      case 4:
      f= divide(a,b);
     printf("%f",f);
      break;
   
   }


}
