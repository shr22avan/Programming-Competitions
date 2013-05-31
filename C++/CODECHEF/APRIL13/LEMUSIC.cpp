#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#define MAX_SIZE 100000
#define ull unsigned long long int
using namespace std;
map<ull,ull> m,low;
struct object
{
	ull b,v,lo;
}bands[MAX_SIZE];
bool myfunction (object i,object j) { return (i.lo < j.lo); }
int main()
{
	int t,n,f;
	ull a,b,e,counter=0;
	scanf("%d",&t);
	while(t--)
	{
		m.clear();
		low.clear();	
		scanf("%d",&n);
		e=counter=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld",&a,&b);
			if(m.count(a)==0)
			{
				bands[counter].b=a;
				m[a]=b;
				low[a]=b;
				counter++;
			}
			else
			{
				m[a]+=b;
				if(low[a]>b)
					low[a]=b;
			}
		}
		for(int i=0;i<counter;i++)
		{
			bands[i].lo=low[bands[i].b];
			bands[i].v=m[bands[i].b]-bands[i].lo;
		}
		sort(bands,bands+counter,myfunction);
		for(int i=0;i<counter;i++)
		{
			e+=(bands[i].lo*(i+1));
			e+=bands[i].v*counter;
		}
		printf("%lld\n",e);
	}
	return 0;
}
