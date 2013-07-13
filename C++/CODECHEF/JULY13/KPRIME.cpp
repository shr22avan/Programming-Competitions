#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 100001
#define getint(n) scanf("%d",&n)
#define putint(n) printf("%d\n",n)
using namespace std;
int dp[MAX][6];
void precompute()
{
	int array[MAX];
	memset(array,0,sizeof(array));
	for(int i = 2 ; i < MAX ; i++) 	{
		if(!array[i]) {
			for(int j = i ; j < MAX ; j += i) {
				array[j]++;
			}
		}
	}
	
	int k[6];
	k[5] = k[1] = k[2] = k[3] = k[4] = 0;
	for(int i=1;i<MAX;i++)
	{
		if(array[i] < 6) {
			k[array[i]]++;
		}
		for(int j = 1; j <= 5 ; j++) {
			dp[i][j] = k[j];
		}	
	}	
	
}
int main()
{
	int t,a,b,k;
	getint(t);
	precompute();
	while(t--)
	{
		getint(a);
		getint(b);
		getint(k);
		putint(dp[b][k]-dp[a-1][k]);
	}
	return 0;
}

