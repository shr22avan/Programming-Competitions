#include<iostream>
#include<cstdio>
#define MAX 70
#define getint(n) scanf("%d",&n)
#define putint(n) printf("%d\n",n)
#define ll long long int
using namespace std;
ll dp[MAX][MAX];
void preprocess() {
	dp[0][0] = 1;
	for(int i = 0 ; i < MAX; i++) {
		for(int j=0 ; j < MAX ; j++) {
			if( i == 0 && j == 0)
				continue;
			if( i-1 < 0 )
				dp[i][j] = dp[i][j-1];
			else if( j-1 < 0)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
	}
}
int main() {
	preprocess();
	int t,n,m,k,val,mini,maxi,v1,v2,v3;
	getint(t);
	while(t--) {
		getint(n);
		getint(m);
		getint(k);
		if(n==1 && m==1) val = 0;
		else if(n==1 || m==1 || k==1) val = k;
		else {
			mini =  min(dp[n-2][m-1], dp[n-1][m-2]); 
			maxi =  max(dp[n-2][m-1], dp[n-1][m-2]); 
			v1 = k/(mini + maxi);
			v2 = k%(mini + maxi);
			val = maxi * v1;
			if(v2 < 2*mini)
				val += v2/2;
			else
				val += (v2 - mini);
		}
		putint(val);
	}
	return 0;
}
