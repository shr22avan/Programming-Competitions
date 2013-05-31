#include <iostream>
using namespace std;
int g[20][20],visited[20],d[20],p[20];
int v,e;
void creategraph()
{
int i,j,a,b,w;
cout<<"\nVertices: ";
cin>>v;
cout<<"\nEdges ";
cin>>e;
for(i=1;i<=v;i++)
for(j=1;j<=v;j++)
g[i][j]=0;
for(i=1;i<=v;i++)
{
p[i]=visited[i]=0;
d[i]=32767;
}
for(j=1;j<=e;j++)
{
cout<<"\nEnter (a,b) and cost\n";
cin>>a>>b>>w;
g[a][b]=g[b][a]=w;
}
}
void prim()
{
int current,totalvisited,mincost,i,min;
current=1;
d[current]=0;
totalvisited=1;
visited[current]=1;
while(totalvisited!=v)
{
for(i=1;i<=v;i++)
{
if(g[current][i]!=0)
if(visited[i]==0)
if(d[i]>g[current][i])
{
d[i]=g[current][i];
p[i]=current;
}
}
min=32767;
for(i=1;i<=v;i++)
{
if(visited[i]==0)
if(d[i]<min)
{
min=d[i];
current=i;
}
}
visited[current]=1;
totalvisited++;
}
mincost=0;
for(i=0;i<=v;i++)
mincost+=d[i];
cout<<"\nMin cost ="<<mincost;
cout<<"\nMin span Tree: ";
for(int i=2;i<=v;i++)
cout<<"\nVertex "<<i<<" is connected to "<<p[i];
}
int main()
{
int i;
creategraph();
prim();
return 0;
}
