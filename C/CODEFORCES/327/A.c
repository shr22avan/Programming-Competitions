#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define getint(a) scanf("%d",&a)
int main()
{
	int i,j,k,n,a[1000],dp[100][100];
	getint(n);
	for(i=0;i<n;i++)
		getint(a[i]);
	int b[1000];
	memset(dp,0,sizeof(dp));
	j=0;
	for(i=0;i<n;i++)
		dp[i][i]=(a[i]==0);
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=n-i;j++)
		{
			dp[j][j+i-1] = dp[j][j+i-2] + (a[j+i-1]==0);
		}
	}
	k=-100;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(dp[i][j]-(j-i+1-dp[i][j])>k)
				k=2*dp[i][j]-j+i-1;
		}
	}
		j=0;
		for(i=0;i<n;i++)
			if(a[i]==1) j++;
		j+=k;
		printf("%d\n",j);
}
