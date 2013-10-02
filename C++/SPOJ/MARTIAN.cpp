#include<iostream>
#include<cstdio>
#include<cstring>
#define getint(a) scanf("%d",&a)
using namespace std;
int main() {
	int n, m, val1, val2, a[500][500], b[500][500], suma[500][500], sumb[500][500], dp[500][500];
	getint(n);
	getint(m);
	while(n!=0 && m!=0) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				getint(a[i][j]);
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				getint(b[i][j]);
			}
		}
		memset(dp,0,sizeof(dp));
		memset(suma,0,sizeof(dp));
		memset(sumb,0,sizeof(dp));

		for(int i = 0; i < n; i++) 
			suma[i][m-1] = a[i][m-1];

		for(int j = 0; j < m; j++)
			sumb[n-1][j] = b[n-1][j];

		for(int i = 0; i < n; i++) {
			for(int j = m-2; j >= 0; j--) {
				suma[i][j] = suma[i][j-1] + a[i][j];
			}
		}

		for(int i = 0; i < m; i++) {
			for(int j = n-2; j >= 0; j--) {
				sumb[j][i] = sumb[j-1][i] + b[j][i];
			}
		}

		dp[n-1][m-1] = max(a[n-1][m-1], b[n-1][m-1]);
		
		for(int i = n - 2, j = m - 2; j >= 0 && i >= 0; i--, j--) {
			val1 = dp[i][j+1];
			val2 = dp[i+1][j];
			dp[i][j] = max(val1, val2);
		}
	}
	return 0;
}
