#include "stdio.h"
#include "time.h"

int suma()
{
 int i,j,sum=0,a[2][3];
 
  for(i=0;i<2;i++)
     for(j=0;j<3;j++)
        a[i][j] = 2;
  

  for(i=0;i<2;i++)
     for(j=0;j<3;j++)
      sum =+  a[i][j];

  
}


int sumb()

{
     int i,j,sum=0,a[2][3];
 
  for(i=0;i<2;i++)
     for(j=0;j<3;j++)
        a[i][j] = 2;
  

 
     for(j=0;j<3;j++)
      for(i=0;i<2;i++)
      sum +=  a[j][i];


}

int main ()
{
 clock_t time1,time2,time3;
 long temp=10000000,all1,all2;
 double dur1,dur2,ave1,ave2;
 int x=0,y=0;
 all1=temp;
 all2=temp;
 time1=clock();
 while(all1!=0)
{
       suma();
       all1--;
}
 time2=clock();
 while(all2!=0)
{
       sumb();
       all2--;
}

 time3=clock();
 dur1=(double)(time2-time1)/CLOCKS_PER_SEC;
 dur2=(double)(time3-time2)/CLOCKS_PER_SEC;
 printf("time to run suma is %f sec \n ",dur1);
 printf("time to run sumb is %f sec   ",dur2);
 return 0; 

}
