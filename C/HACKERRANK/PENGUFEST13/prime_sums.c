#include<stdio.h>
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==0 || n==1)
			printf("False\n");
		else
			printf("True\n");
	}
	return 0;
}
