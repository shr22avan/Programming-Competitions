#include<stdio.h>
#define MOD 1000000007
#define ull unsigned int
#define d1 1001
#define d2 11
ull dp[d1][d2];
int main()
{
	int i,j,t,n,k;
	for(i=1;i<d2;i++)
	{
		dp[2][i]=i;
		dp[3][i]=i*(i-1);
	}
	for(i=4;i<d1;i++)
		for(j=1;j<d2;j++)
			dp[i][j]=(((dp[i-2][j]*j)%MOD)+(dp[i-1][j]*(j-1))%MOD)%MOD;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		printf("%lld\n",dp[n][k]);
	}
	return 0;
}
