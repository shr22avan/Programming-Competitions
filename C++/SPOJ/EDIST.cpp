#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 2001
using namespace std;
#define ll long long
#define getint(n)
#define getstring(a) scanf("%s",a)
int dp[MAX][MAX];
void memoize(char a[],char b[], int dp[][MAX], int posa, int posb)
{
	if(posa < 0 || posb < 0)
	{
		;
	}
	else if(posa == 0 || posb ==0)
	{
		if(a[posa] == b[posb])
			dp[posa][posb] = 1;
	}
	else if(a[posa] == b[posb])
	{
		memoize(a,b,dp,posa-1,posb-1);
		dp[posa][posb] = dp[posa-1][posb-1] + 1;
	}
	else 
	{
		memoize(a,b,dp,posa-1,posb);
		memoize(a,b,dp,posa,posb-1);
		dp[posa][posb] = max(dp[posa-1][posb], dp[posa][posb-1]);
	}
}  
int main()
{
	char a[MAX],b[MAX];
	int t, posa, posb, l1, l2;
	bool mark1[MAX], mark2[MAX];
	memset(dp,0,sizeof(dp));
	memset(mark1,false,sizeof(mark1));
	memset(mark2,false,sizeof(mark2));
	getint(t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(mark1,false,sizeof(mark1));
		memset(mark2,false,sizeof(mark2));
		getstring(a);
		getstring(b);
		l1 = strlen(a) - 1, l2 = strlen(b) - 1;
		memoize(a,b,dp,l1,l2);
		posa = l1, posb = l2;
		while(posa >= 0 && posb >= 0)
		{
			if(a[posa] == b[posb])
			{
				mark1[posa] = true;
				mark2[posb] = true;
				posa--;
				posb--;
			}
			else
			{
				if(dp[posa-1][posb] > dp[posa][posb-1])
					posa--;
				else 
					posb--;
			}
		}
	}
	return 0;
}
