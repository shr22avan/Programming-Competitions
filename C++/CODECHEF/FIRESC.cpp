#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int t,n,m,p,q;
	vector<int> adj[100000];
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&p,&q);
			adj[p].push_back(q);
		}
	}
	return 0;
}
