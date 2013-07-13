#include<stdio.h>
#define getint(n) scanf("%d",&n)
#define getdouble(n) scanf("%f",&n)
int main()
{
	int t;
	float p,val;
	getint(t);
	while(t--)
	{
		getdouble(p);
		if(p>0.5)
			p=1-p;
		val=10000*(p-2*p*p+1);
		printf("%.6f\n",val);
	}
	return 0;
}
