#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define getint(a) scanf("%d",&a)
#define emptyq(q) while(!q.empty()) q.pop()
#define yes printf("YES\n")
#define no  printf("NO\n")
using namespace std;
struct interval {
	int x,y;
};

int adjlist[100][100];
int c[100],counter=0,visited[100];
interval z[1000];
int bfs(int a,int b)
{
	queue<int> q;
	q.push(a);
	while(!q.empty())
	{
		if(q.front()==b)
			return 1;
		else
		{
			if(!visited[q.front()])
			{
				for(int i=0;i<c[q.front()];i++)
				{
					q.push(adjlist[q.front()][i]);
				}
				visited[q.front()]=1;
				q.pop();
			}
			else
				q.pop();
		}
	}
	return 0;
}
int main()
{
	int n,k,a,b;
	getint(n);
	memset(c,0,sizeof(c));
	while(n--)
	{
		getint(k);
		getint(a);
		getint(b);
		if(k==1)
		{
			
			z[counter].x=a;
			z[counter].y=b;
			counter++;
			if(counter!=1)
			{
				for(int i=0;i<counter-1;i++)
				{
					if(z[counter-1].x>z[i].x && z[counter-1].x<z[i].y)
					{
						adjlist[counter-1][c[counter-1]]=i;
						c[counter-1]++;
					}
					else if(z[counter-1].y>z[i].x && z[counter-1].y<z[i].y)
					{
						adjlist[counter-1][c[counter-1]]=i;
						c[counter-1]++;
					}

					if(z[i].x>z[counter-1].x && z[i].x<z[counter-1].y)
					{
						adjlist[i][c[i]]=counter-1;
						c[i]++;
					}
					else if(z[i].y>z[counter-1].x && z[i].y<z[counter-1].y)
					{
						adjlist[i][c[i]]=counter-1;
						c[i]++;
					}
				}
			}	
		}
		if(k==2)
		{
			a--,b--;
			memset(visited,0,sizeof(visited));
			if(bfs(a,b))
				yes;	
			else
				no;		
		}
	}
	return 0;
}
