#include<iostream>
#include<cstdio>
#include<algorithm>
#define getint(a) scanf("%d",&a)
using namespace std;
int main()
{
	int n,d,a[100000];
	getint(n);
	getint(d);
	for(int i=0;i<n;i++)
		getint(a[i]);
	sort(a,a+n);
	int val = 0;
	for(int i=0;i<n-1;i++)
	{
		if(a[i+1] - a[i] <= d)
			val++,i++;
	}
	printf("%d\n",val);
	return 0;
}
