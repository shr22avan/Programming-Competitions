#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
#define MAX_SIZE 20001
#define ull unsigned long long int
using namespace std;
struct object
{
	ull number;
	int remainder;
	int d;
};
void display(object temp)
{
	stack<bool> s;
	while(temp.d)
	{
		s.push(temp.number&1);
		temp.number >>=1;
		temp.d--;
	}
	while(!s.empty())
	{
		printf("%d",(s.top()==true));
		s.pop();
	}
	printf("\n");
}
void answer(int n)
{
	bool flag=false;
	bool rems[MAX_SIZE];
	queue<object> q;
	object temp;
	temp.number=1;
	temp.remainder=1%n;
	temp.d=1;
	q.push(temp);
	memset(rems,0,sizeof(rems));
	while(!q.empty() && !flag)
	{
		temp=q.front();
		q.pop();
		if(temp.remainder==0)
			flag=true;
		else
		{
			temp.number<<=1;
			temp.remainder*=10;
			temp.remainder%=n;
			temp.d++;
			if(!rems[temp.remainder])
			{
				q.push(temp);
				rems[temp.remainder]=true;
			}
			temp.number|=1;
			temp.remainder+=1;
			temp.remainder%=n;
			if(!rems[temp.remainder])
			{
				q.push(temp);
				rems[temp.remainder]=true;
			}		}
	}
	display(temp);
}
int main()
{
	int k,n;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&n);
		answer(n);
	}
	return 0;
}
