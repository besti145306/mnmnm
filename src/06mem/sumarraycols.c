int sumarraycols(int a[M][N])
{
int i,j,sum=0;

for(i=0;i<N;i++)
for(j=0;j<M;j++)
sum+=a[i][j];
return sum;
}
