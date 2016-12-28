double data[MAXELEMS];

void test(int elems,int stride)
{
int i;
double result=0.0;
volatile double sink;

for(i=0;i<elems;i+=stride){
result +=data[i];
}
sink=result;
}

double run(int size,int stride,double Mhz)
{
double cycles;
int elems=size/sizeof(double);

test(elems,stride);
cycles=fcyc2(test,elems,stride,0);
return (size/stride)/(cycles/Mhz);
}
