#include<iostream>
#include<cstdio>
#include<cstring>
#define getint(a) scanf("%d",&a)
#define MAX 1000
using namespace std;
int main() {
	int t,n,k,answer,a[MAX];
	char op[4];
	getint(t);
	while(t--) {
		getint(n);
		getint(k);
		getint(answer);
		for(int  i = 0; i < n; i++) {
			getint(a[i]);
		}
		scanf("%s",op);
		if(k == 0)
			printf("%d\n",answer);
		else {
			if(strcmp(op,"OR") == 0){
				for(int i = 0; i < n; i++) {
					answer = answer | a[i];
				}
			}
			else if(strcmp(op,"AND") == 0) {
				for(int i = 0; i < n; i++) {
					answer = answer & a[i];
				}
			}
			else if(strcmp(op,"XOR") == 0) {
				if(k%2 == 0) {
					answer = answer;
				}
				else {
					for(int i = 0; i < n; i++) {
						answer = answer ^ a[i];
					}
				}
			}
			printf("%d\n",answer);
		}
	}
	return 0;
}
