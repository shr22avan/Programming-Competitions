#include<stdio.h>
int main()
{
	int t,n,c,q,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&c,&q);
		while(q--)
		{
			scanf("%d%d",&l,&r);
			if(l<=c && c<=r)
				c=r-(c-l);
		}
		printf("%d\n",c);
	}
	return 0;
}
