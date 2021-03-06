#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define MAX_SIZE 6677
#define MOD 747474747
#define ull unsigned long long int
#define INFINITY (1<<30)
int n,d,counter1,counter2;
struct vertex
{
	int parent,id,c[5],marked,key,count;
};
vector<vertex> a;
int distance1(vertex v1,vertex v2)
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
int fastpow(ull a, ull b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	else
	{
		ull t=fastpow(a,b/2);
		t=t*t;
		if(t>=MOD)
			t%=MOD;
		t=t*fastpow(a,b%2);
		if(t>=MOD)
			t%=MOD;
		return t;
	}
}
int equal(vertex a, vertex b)
{
	int i;
	for(i=0;i<d && a.c[i]==b.c[i];i++);
	if(i<d)
		return 0;
	else
		return 1;
}
void swap(int &a,int &b)
{
	int c=a;
	a=b;
	b=c;
}
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const vertex& lhs, const vertex &rhs) const
  {
   	return (lhs.key < rhs.key);
  }
};
int main()
{
	counter1=0;
	int t,e,from,s2,to,counter;
	ull score,s1,tempscore;
	vertex temp,temp1;
	priority_queue< vertex, vector<vertex>, mycomparison > mypq;
	scanf("%d",&t);
	while(t--)
	{
		a.clear();
		counter=0;
		while(!mypq.empty())
			mypq.pop();
		score=1;
		scanf("%d%d",&n,&d);
		e=0;
		for(int i=0,j;i<n;i++)
		{
			for(j=0;j<d;j++)
			{
				scanf("%d",&temp.c[j]);
			}
			temp.id=counter;
			temp.marked=0;
			temp.key=-INFINITY;
			temp.count=1;
			temp.parent=-1;
			a.push_back(temp);
			counter++;
		}
		a[0].key=0;
		mypq.push(a[0]);
		while(e<n)
		{
			if(mypq.empty())
				break;
			temp=mypq.top();
			mypq.pop();
			if(a[temp.id].marked)
				continue;
			a[temp.id].marked=1;
			if(temp.parent!=-1)
			{
				score*=temp.key;
				if(score>=MOD)
					score%=MOD;
			}	
			e++;	
			for(int i=0;i<a.size();i++)
			{
				if(a[i].marked || equal(temp,a[i]))
					continue;
				a[i].parent=temp.id;
				s2=distance1(a[i],temp);
				if(a[i].key<s2)
				{
					a[i].key=s2;
				}
				mypq.push(a[i]);
			}		
		}
		printf("%lld\n",score);				
	}
	return 0;
}
