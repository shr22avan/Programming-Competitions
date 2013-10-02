#include<iostream>
#include<cstdio>
#include<queue>
#define getint(a) scanf("%d",&a)
#define MAX1 10000
#define MAX2 100
#define ll long long
using namespace std;
int main() {
	int t,n,m,a[MAX1],c,v;
	ll val = 0;
	priority_queue<int> pq[MAX2];
	getint(t);
	while(t--) {
		val = 0;
		getint(n);
		getint(m);
		for(int i = 0; i < m; i++) {
			getint(a[i]);
		}
		for(int k = 0; k < n; k++) {
			getint(c);
			for(int j = 0; j < c; j++) {
				getint(v);
				pq[k].push(v);
			}
		}
		for(int i = 0; i < m; i++) {
			if(!pq[a[i]].empty()) {
				val += pq[a[i]].top();
				pq[a[i]].pop();
			}
			else
			{
				val += 0;
			}
		}
		printf("%lld\n", val);
		for(int i = 0; i < n; i++) {
			while(!pq[i].empty()) {
				pq[i].pop();
			}
		}
	}
	return 0;
}
