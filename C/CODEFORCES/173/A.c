#include<stdio.h>
int main()
{
	int x=0,n=0;
	char a[4];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",a);
		if(a[0]=='+' || a[1]=='+' || a[2]=='+')
			x++;
		else if(a[0]=='-' || a[1]=='-' || a[2]=='-')
			x--;
	}
	printf("%d\n",x);
	return 0;
}
