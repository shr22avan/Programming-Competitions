/*d
s-1 C n-1
n
e->k to m-1
sigma(m-1 C e * s-m C n-e-1)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double C(int a, int b)
{
	if(b>a)
		return 0.0;
	double c=1;
	int i,j,k,l,m,n,o;
	for(i=a,j=a-b;j>0;j--,i--)
	{
		c*=(i*1.0);
		c/=(j*1.0);
	}
	for(;i>b;i--)
		c*=(i*1.0);
	return c;
}
int main()
{
	int t,s,n,m,k;
	double val1=1,val2=1,val3=1;
	scanf("%d",&t);
	while(t--)
	{
		val1=1,val2=0,val3=1;
		scanf("%d%d%d%d",&s,&n,&m,&k);
		val1=C(s-1,n-1);
		for(int e=k;e<=m-1;e++)
		{
			val3=C(m-1,e) * C(s-m,n-e-1);
			val2+=val3;
		}
		val2/=val1;
		printf("%f\n",val2);		
	}
	return 0;
}
