#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 100
#define MAX2 10001
#define H 100.00000
#define O 1.00000

#define getint(a) scanf("%d",&a)

using namespace std;

int main() {

	int t, n, a[MAX], sum, q;
	float probability[MAX2], op, p[MAX], s;
	getint(t);
	while(t--) {

		sum = 0, op = 0;
		getint(n);

		for(int i = 0; i < n; i++) {
			getint(a[i]);
			sum += a[i];
		}

		for(int i = 0; i < n; i++) {
			getint(q);
			p[i] = q / H;
		}

		memset(probability, 0, sizeof(probability));

		probability[a[0]] = p[0];
		probability[0] = (O - p[0]);

		for(int i = 1; i < n; i++)
			for(int j = sum; j >=0; j--) {
				probability[j] *= (O - p[i]);
				if(j - a[i] >= 0) 
					probability[j] += probability[j-a[i]] * p[i];
			}

		for(int i = sum/2 + sum%2; i <= sum; i++)
			op += probability[i]; 

		printf("%f\n",op);

	}
	return 0;
}
