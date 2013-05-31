#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define MAX_SIZE 7000
#define MOD 747474747
#define ull unsigned long long int
#define INFINITY 0
int n,d,counter1,counter2;
struct vertex
{
	int unset,parent,id,c[5],marked,key;
};
vector<vertex> a;
ull distance1(vertex v1,vertex v2)
{
	ull i,v=0,temp;
	for(i=0;i<d;i++)
	{
		temp=(v1.c[i]-v2.c[i])*(v1.c[i]-v2.c[i]);
		if(temp>=MOD)
		temp%=MOD;
		v+=temp;
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
  	if(lhs.marked && !rhs.marked)
  		return 1;
  	else if(!lhs.marked && rhs.marked)
  		return 0;
   	return (lhs.key < rhs.key);
  }
};
int main()
{
	counter1=0;
	int t,e,s1;
	ull score,qwe;
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
			temp.marked=0;
			temp.key=INFINITY;
			temp.parent=-1;
			temp.unset=1;
			a.push_back(temp);
		}
		e=n;
		//Gonna run Prims Algo
		a[0].key=0;
		a[0].parent=-1;		
		a[0].unset=0;
		pq.push(a[0]);
		score=1;
		while(e>0)
		{	
			temp=pq.top();
			pq.pop();
			if(a[temp.id].marked)
				continue;
			a[temp.id].marked=1;
			e--;
			if(temp.parent!=-1)
			{
				score*=(temp.key);
				if(score>=MOD)
					score%=MOD;
			}
			for(int j=1;j<n;j++)
			{
				if(a[j].marked)
					continue;
				else
				{	
					qwe=distance1(temp,a[j]);
					if(a[j].unset || a[j].key<qwe)
					{
						a[j].unset=0;
						a[j].parent=temp.id;
						a[j].key=qwe;
						pq.push(a[j]);						
					}
				}
			}			
		}
		printf("%lld\n",score);				
	}
	return 0;
}
