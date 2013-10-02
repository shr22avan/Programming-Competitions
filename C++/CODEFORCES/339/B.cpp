#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#define MAX 100000
using namespace std;
#define getint(a) scanf("%d",&a)
int main() {
	int n,m;
	int a[MAX];
	getint(n);
	getint(m);
	for(int i = 0; i < m; i++) {
		getint(a[i]);
	}
	unsigned long long int state = 1, distance = 0;
	for(int  i = 0; i < m; i++) {
		if(state == a[i]) {
			continue;	
		}
		else if(state < a[i]) {
			distance += (a[i] - state);
			state = a[i];
		}
		else {
			distance += (n-state);
			distance++;
			distance += (a[i]-1);
			state = a[i];
		}
	}
	cout<<distance;
	return 0;
}
