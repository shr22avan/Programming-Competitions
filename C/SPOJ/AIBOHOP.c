#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 6101
#define getint(n) scanf("%d",&n)
#define getstring(n) scanf("%s",n)
int dp[6100][6100];
int max(int a,int b)
{
	if(a<b)
		a=b;
	return a;
}
int llcs(char a[])
{
	int length=0,l=strlen(a);
	char b[MAX_SIZE];
	int i,j;
	for(i=0;i<l;i++)
		b[i]=a[l-i-1];
	b[l]='\0';
	for(i=1;i<=l;i++)
	{
		for(j=1;j<=l;j++)
		{
			if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return l-dp[l][l];
}
int main()
{
	int t;
	char a[6101];
	getint(t);
	while(t--)
	{
		getstring(a);
		printf("%d\n",llcs(a));
	}
	return 0;
}
