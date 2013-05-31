#include<stdio.h>
#include<string.h>
int b[100000];
int main()
{
	char a[100001];
	int m,i,j=0;
	scanf("%s",a);
	for(i=1;i<strlen(a);i++)
	{
		if(a[i-1]==a[i])
			j++;
		b[i]=j;
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&i,&j);
		printf("%d\n",b[j-1]-b[i-1]);
	}
	return 0;
}
