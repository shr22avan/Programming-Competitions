#include<iostream>
#include<cstdio>
#define getint(n) scanf("%d",&n)
#define getd(a) scanf("%lf",&a)
using namespace std;
struct object {
	int m;
	double r;
	int c;
}arr[100];
int main() {
	int t,n,m,c,u,index = 0;;
	double d,r,best;
	getint(t);
	while(t--) {
		getd(d);
		getint(u);
		getint(n);
		index = 0;
		for(int  i = 0; i < n; i++) {
			getint(arr[i].m);
			getd(arr[i].r);
			getint(arr[i].c);	
		}
		best = d*u;
		for(int i = 0; i < n; i++) {
			if(arr[i].r * u + arr[i].c/(arr[i].m * 1.0) < best) {
				best = (arr[i].r * u + arr[i].c/(arr[i].m * 1.0));
				index = i + 1;
			}
		}
		printf("%d\n",index);
	}
	return 0;
}
