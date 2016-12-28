void clear3(point *p, int n)
{
  int i,j;


  for(j=0; j<3; j++)
  {
    for(i=0; i<n; i++)
    p[i].vel[j] = 0;
    for(i=0; i<n; i++)
	p[i].vel[j] = 0;
  }
 
}
