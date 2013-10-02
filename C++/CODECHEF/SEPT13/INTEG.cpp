#include<iostream>
#define MAX 100000
#define getint(a) scanf("%d",&a)
using namespace std;
int main() {
	int n,a[MAX],x;
	getint(n);
	for(int i = 0; i < n; i++) {
		getint(a[i]);
	}
	getint(x);
	return 0;
}
