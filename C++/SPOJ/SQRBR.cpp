#include<iostream>
#include<cstdio>
#include<cstring>
#define ARR_SIZE 30
#define getint(n) scanf("%d",&n)
using namespace std;
int main()
{
	int d,n,k,dp[ARR_SIZE][ARR_SIZE],hash[50],a;
	getint(d);
	while(d--)
	{
		getint(n);
		getint(k);
		memset(hash,0,sizeof(hash));
		for(int i=0;i<=n;i++)
			memset(dp[i],0,sizeof(dp[i]));
		for(int i=0;i<k;i++)
		{
			getint(a);
			hash[a]=1;
		}
		if(!hash[2])
			dp[1][1]=1;
		for(int i=0;i<n;i++)
		{
			if(!hash[i])
				dp[i][0]=1;
		}
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(hash[i+j])
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
		printf("%d\n",dp[n][n]);
	}
	return 0;
}
