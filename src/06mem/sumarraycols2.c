int sumarraycols2(int a[M][N])
{
int i,j,sum=0;

for (j=0;j<N;j++)
for (i=0;i<M;i++)
sum+=a[i][j];
return sum;
}
