#include "stdio.h"
#include "head.h"

void main ()
{

   int a,b,c;


   printf("input a,b:");
   scanf("%d",&a); 
   scanf("%d",&b);

   printf("1:add 2:subtract 3:multiply 4 divide");
   scanf("%d",&c);
   switch(c)
   {
      case 1:
       add(a,b);
      break;
     
      case 2:
       subtract(a,b);
      break;  

      case 3:
       multiply(a,b);
      break;

      case 4:
       divide(a,b);
      break;
   
   }


}
