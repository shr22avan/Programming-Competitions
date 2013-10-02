#include<iostream>
#include<cstdio>
#define getint(a) scanf("%lld",&a)
#define ll long long
using namespace std;
int main() {
	ll t,n,k;
	getint(t);
	while(t--) {
		getint(n);
		getint(k);
		if(k == 0){
			printf("%lld %lld\n",0LL,n);
			continue;
		}	
		printf("%lld %lld\n",n/k,n%k);
	}
}
