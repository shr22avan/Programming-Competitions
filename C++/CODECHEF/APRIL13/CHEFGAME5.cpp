#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define MAX_SIZE 6677
#define MOD 747474747
#define ull unsigned long long int
#define INFINITY 1<<31
int n,d,counter1,counter2;
struct vertex
{
	int id,c[5],marked,key,count,tcount;
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
ull fastpow(int a, int b)
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
struct edge{
	int id1,id2;
	ull distance;
};
bool compare(const edge &i, const edge &j)
{
	return i.distance>j.distance;
}
vector <edge> b;
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
int main()
{
	counter1=0;
	int t,e,from,to;
	
	ull score,s1,s2,tempscore;
	vertex temp;
	edge t1;
	scanf("%d",&t);
	while(t--)
	{
		a.clear();
		b.clear();
		score=1;
		scanf("%d%d",&n,&d);
		e=n;
		for(int i=0,j;i<n;i++)
		{
			for(j=0;j<d;j++)
			{
				scanf("%d",&temp.c[j]);
			}
			temp.id=i;
			temp.marked=0;
			for(j=0;j<a.size();j++)
			{
				if(equal(a[j],temp))
				{
					a[j].count++;
					a[j].tcount++;
					break;
				}
			}
			if(j==a.size())
			{
				temp.count=1;
				temp.tcount=1;
				a.push_back(temp);
			}
		}
		//Gonna do kruskals
		for(int i=0;i<a.size();i++)
		{
			t1.id1=i;
			for(int j=i+1;j<a.size();j++)
			{
				t1.id2=j;
				t1.distance=distance1(a[i],a[j]);
				b.push_back(t1);					
			}
		}
		sort(b.begin(),b.end(),compare);
		for(int i=0;i<b.size() && e;i++)		
		{
			if(a[b[i].id1].marked && a[b[i].id2].marked && a[b[i].id1].tcount==a[b[i].id1].count && a[b[i].id2].tcount==a[b[i].id2].count)
				continue;
			else 
			{
				from=b[i].id1,to=b[i].id2;
				if(!a[from].marked && !a[to].marked)
				{
					if(a[from].count>a[to].count)
					{
						swap(from,to);
					}
					a[from].tcount=a[from].count			;
					a[from].marked=1;
					a[to].tcount=a[to].count;
					a[to].marked=1;
					e-=a[from].count;
					e-=a[to].count;
					tempscore=fastpow(b[i].distance,a[to].count);
					if(tempscore>MOD)
						score*=(tempscore%MOD);
					else
					score*=(tempscore);
					if(score>=MOD)
						score%=MOD;
										
				}
				else
				{
				 	if(!a[from].marked && a[to].marked)
				 	{
						swap(from,to);
				 	}
			 		a[to].tcount=a[to].count;
			 		a[to].marked=1;
			 		e-=a[to].count;
			 		tempscore=fastpow(b[i].distance,a[to].count);
			 		if(tempscore>=MOD)
			 			tempscore%=MOD;
			 		score*=tempscore;
			 		if(score>=MOD)
			 			score%=MOD;
			 	}									
			}
		}
		printf("%lld\n",score);				
	}
	return 0;
}
