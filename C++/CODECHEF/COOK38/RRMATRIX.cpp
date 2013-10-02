#include<iostream>
#include<cstdio>
#include<cstring>
#define getint(a) scanf("%d",&a)
#define MAX 1000
using namespace std;
int gcd(int a, int b) {
	if(a == 1 || b == 1)
		return 1;
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	if(a == b)
		return a;
	else if(a > b)
		return gcd(a%b,b);
	else
		return gcd(a,b%a);
}
int main() {
	int t,n,m,a,b,answer,h;
	getint(t);
	while(t--) {
		getint(n);
		getint(m);
		h = gcd(n-1,m-1);
		answer = h+1;
		printf("%d\n",answer);
	}
	return 0;
}
