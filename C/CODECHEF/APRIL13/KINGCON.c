#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 4000
int adj[MAX_SIZE][MAX_SIZE],counter[MAX_SIZE],visited[MAX_SIZE],low[MAX_SIZE],num[MAX_SIZE],parent[MAX_SIZE],node,artpoints;
int dfs(int start)
{
	int i,j,k=-1;
	num[start]=low[start]=node;
	node++;
	for(i=0;i<counter[start];i++)
	{
		if(!visited[adj[start][i]])
		{
			parent[adj[start][i]]=start;
			visited[adj[start][i]]=1;
			dfs(adj[start][i]);
			j=low[adj[start][i]];
			if(j>num[start])
				if(k==-1)
					k=1;
				else
					k++;			
		}
		else if(adj[start][i]!=parent[start])
			j=num[adj[start][i]];
		else
			continue;
		if(low[start]>j)
			low[start]=j;
	}
	if(k!=-1)
		artpoints++;
	return low[start];
}
int main()
{
	int t,n,m,k,i,j,l,o,e;
	scanf("%d",&t);
	while(t--)
	{
		node=1;
		memset(adj,0,sizeof(adj));
		memset(counter,0,sizeof(counter));
		memset(visited,0,sizeof(visited));
		memset(low,0,sizeof(low));
		memset(num,0,sizeof(num));				
		memset(parent,0,sizeof(parent));		
		scanf("%d%d%d",&n,&m,&k);
		artpoints=0;
		while(m--)
		{
			scanf("%d%d",&e,&o);
			adj[e][counter[e]]=o;
			adj[o][counter[o]]=e;			
			counter[e]++;
			counter[o]++;
		}
		parent[o]=-1;
		visited[o]=1;
		dfs(o);
		e=0;
		artpoints--;
		for(i=0;i<n;i++)
			if(parent[i]==o)
				e++;
		if(e>1)
			artpoints++;
		printf("%d\n",k*artpoints);		
	}
	return 0;
}
