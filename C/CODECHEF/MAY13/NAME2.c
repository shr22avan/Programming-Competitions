#include<stdio.h>
#include<string.h>
int main()
{
	char a[25001],b[25001];
	int t,i,j,k,l1,l2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",a,b);
		l1=strlen(a);
		l2=strlen(b);
		if(l1<=l2)
		{
			for(i=0,j=0,k=0;j<l2 && i<l1;j++)
			{
				if(a[i]==b[j])
				{
					i++;
					k++;
				}
			}
			if(k==l1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			for(i=0,j=0,k=0;j<l1 && i<l2;j++)
			{
				if(b[i]==a[j])
				{
					i++;
					k++;
				}
			}
			if(k==l2)
				printf("YES\n");
			else
				printf("NO\n");
		}
		
	}
	return 0;
}
