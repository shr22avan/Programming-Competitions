#include<stdio.h>
#define getint(a) scanf("%d",&a)
#define putint(a) printf("%d",a)
#define putintl(a) printf("%d\n",a)
#define MAX 100000
int main() {
	int n, a[MAX], b;
	getint(n);
	for(int i = 0; i < n; i++) {
		getint(a[i]);
	}
	getint(b);
	return 0;
}
