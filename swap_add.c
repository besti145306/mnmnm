

int swap_add (int *xp,int *yp)
{
     int x = *xp;
     int y = *yp;
    
     *xp = y;
     *yp = x;
 
     return x+y;
   
}

