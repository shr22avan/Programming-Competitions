#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
#define MAX 3000
vector <int> g[MAX];
bool visited[MAX];
int low[MAX];
int num[MAX];
int level[MAX];
int counter=0;
int ans=0;
int artpts[MAX];
int artptssize=0;
int numchildren=0;
int artpoint(int s)
{
	counter++;
	visited[s]=1;
	num[s]=counter;
	low[s]=num[s];
	int size=g[s].size();
	for(int i=0;i<size;i++)
	{
		int x=g[s][i];
		if(!visited[x])
		{
			if(level[s]==0)numchildren++;
				level[x]=level[s]+1;
			artpoint(x);
			low[s]=min(low[s],low[x]);
			if(numchildren>1 && level[s]==0)
			{
				int flag=0;
				for(int j=0;j<artptssize;j++)
				{
					if(artpts[j]==s)
					{
						flag=1;
						break;
					}
				}
				if(!flag)
				{
					artpts[artptssize++]=s;
					ans++;
				}
			}
			else if(level[s]!=0)
			{
				if(low[x]>=num[s])
				{
					int flag=0;
					for(int j=0;j<artptssize;j++)
					{
						if(artpts[j]==s)
						{
							flag=1;
							break;
						}
					}
					if(!flag)
					{
						artpts[artptssize++]=s;
						ans++;
					}
				}
			}
		}
		else if(level[x]<level[s]-1)
			low[s]=min(low[s],num[x]);
	}
	return ans;
}
void addedge(int a,int b)
{
	g[a].push_back(b);
	g[b].push_back(a);
}
int main()
{
	int t,k,m,n,a,b,e;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		for(int i=0;i<MAX;i++)
		{
			visited[i]=0;
			num[i]=0;
			low[i]==0;
			level[i]=0;
			g[i].clear();
		}
		counter=0;
		ans=0;
		artptssize=0;
		numchildren=0;
		scanf("%d%d%d",&n,&m,&e);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			addedge(a,b);
		}
		int ans=artpoint(a);
		printf("%d\n",e*ans);
	}
	return 0;
}

