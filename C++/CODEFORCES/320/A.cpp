#include<iostream>
#include<cstdio>
#include<stack>
#define getint(a) scanf("%d",&a);
using namespace std;
int main()
{
	int n,a[20],counter=0;
	getint(n);
	stack<int> s;
	while(n)
	{
		s.push(n%10);
		n/=10;
	}
	while(!s.empty())
	{
		a[counter++]=s.top();
		s.pop();
	}
	bool flag=false;
	for(int i=0;i<counter;i++)
	{
		if(a[i]!=1 && a[i]!=4) {
			printf("NO\n");
			return 0;
		}
		else
		{
			if(a[i]==4)
			{
				if(!((i-1>=0 && a[i-1]==1) ||( i-2>=0 && a[i-2]==1))) {
					printf("NO\n"); return 0;}
					
			}
		}
	}
	printf("YES\n");
	return 0;
}
