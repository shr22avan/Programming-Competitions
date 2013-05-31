#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define MAX_SIZE 6666
#define MOD 747474747
#define ull unsigned long long int
#define INFINITY 1<<31
int n,d,counter1,counter2;
struct vertex
{
	int id,used,c[5],marked,key;
};
vector<vertex> a;
ull distance1(vertex v1,vertex v2)
{
	ull i,v=0;
	for(i=0;i<d;i++)
	{
		v+=(v1.c[i]-v2.c[i])*(v1.c[i]-v2.c[i]);
		if(v>=MOD)
			v%=MOD;
	}
	return v;
}
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const vertex& lhs, const vertex &rhs) const
  {
    if (reverse) return (lhs.key > rhs.key);
    else return (lhs.key < rhs.key);
  }
};
int equal(vertex k1,vertex k2)
{
	int l=0;
	for(int i=0;i<d;i++)
	{
		if(k1.c[i]==k2.c[i])
			l++;	
	}
	return (l==d);
}
int main()
{
	counter1=0;
	int t,e;
	ull score,s1;
	vertex temp;
	priority_queue< vertex, vector<vertex>, mycomparison > pq;		
	scanf("%d",&t);
	while(t--)
	{
		a.clear();
		while(!pq.empty())
			pq.pop();
		score=1;
		scanf("%d%d",&n,&d);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<d;j++)
			{
				scanf("%d",&temp.c[j]);
			}
			temp.id=i;
			temp.used=temp.marked=0;
			temp.key=INFINITY;
//			a[counter1]=temp;
			a.push_back(temp);
		}
		e=n;
		//Gonna run Prims Algo
		pq.push(a[0]);
		score=1;
		s1=-1;
		while(e>0)
		{	
			temp=pq.top();
			pq.pop();
			if(a[temp.id].used)
				continue;					
			if(s1!=-1)
			{
				score*=distance1(temp,a[s1]);
				if(score>=MOD)
					score%=MOD;
			}
			s1=temp.id;
			a[temp.id].marked=1;
			e--;			
			for(int j=temp.id+1;j<n;j++)
			{
				if(equal(temp,a[j]))
				{
					a[j].used=1;
					continue;
				}
				else
				{
					if(a[j].marked)
						continue;
					else
					{
						pq.push(a[j]);
						a[j].key=-distance1(temp,a[j]);
					}
				}
			}				
		}
		printf("%lld\n",score);				
	}
	return 0;
}
