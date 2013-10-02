#include<stdio.h>
#include<string.h>
#define MAX 501
#define getint(a) scanf("%d",&a);
#define getstring(a) scanf("%s",a);
void add(char *a, char *b) {
	int la = strlen(a), lb = strlen(b), i, j;
	char c[2*MAX];
	if(la > lb)
		i = lb-1, j = la - 1;
	else
		i = la-1, j = lb - 1;
	for(; i>=0; i--) {
		
	}
}
int main() {
	int t;
	char a[MAX], b[MAX], op;
	getint(t);
	while(t--) {
		getstring(a);
		scanf("%c",op);
		getstring(b);
		switch(op) {
		case '+': add(a,b); break;
		case '-': subtract(a,b); break;
		case '*': multiply(a,b); break;
		}
	}
	return 0;
}
