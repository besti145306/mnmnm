#include "func.h"

void inplace_swap(int *x,int *y)
{
  *y=*x^*y;
  *x=*y^*x;
  *y=*y^*x;
}
