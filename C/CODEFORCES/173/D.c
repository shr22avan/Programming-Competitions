#include<stdio.h>
int main()
{
	int n,a[3];
	scanf("%d",&n);
	if(n==1)
	{
		scanf("%d",a[0]);
		if(a[0]==0)
			printf("BitAryo\n");
		else
			printf("BitLGM\n");
	}
	else if(n==2)
	{
		scanf("%d%d",&a[0],&a[1]);
		if(a[0]==0 && a[1]==0)
			printf("BitAryo\n");
		else if(a[0]==0 || a[1]==0)
			printf("BitLGM\n");
		else
		{
			int v=min(a[0],a[1]);
			a[0]-=v;
			a[1]-=v;
			if(a[0]==a[
		}
						
	}
	return 0;
}
