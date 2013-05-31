#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n>=0)
		printf("%d\n",n);
	else
	{
		if((n%10)>=((n%100)/10))
			printf("%d\n",(n/100)*10+(n%10));
		else
			printf("%d\n",(n/10));
	}
	return 0;
}
