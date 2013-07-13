#include<iostream>
#include<cstdio>
#define MAX 70
#define getint(n) scanf("%d",&n)
#define putint(n) printf("%d\n",n)
#define ll long long int
using namespace std;
int main() {
	int t,n,m,k,val;
	getint(t);
	while(t--) {
		getint(n);
		getint(m);
		getint(k);	
		if ( n == 1 && m == 1)
			val = 0;
		else if ( n == 1 || m == 1)
			val = k;
		else
			val = k/2 + k%2;
		putint(val);
	}
	return 0;
}
