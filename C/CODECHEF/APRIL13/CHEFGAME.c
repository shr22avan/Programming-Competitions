#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_SIZE 6666
#define MOD 747474747
#define ull unsigned long long int
int n,d,counter1,counter2;
typedef struct vertex
{
	int used;
	int c[5];
	int marked;
} vertex;
vertex a[MAX_SIZE];
typedef struct edge
{
	int id1,id2;
} edge;
edge b[222111];
ull distance(vertex a,vertex b)
{
	ull i,v=0;
	for(i=0;i<d;i++)
	{
		v+=(a.c[i]-b.c[i])*(a.c[i]-b.c[i]);
		if(v>=MOD)
			v%=MOD;
	}
	return v;
}
int compare(const void *t1, const void *t2)
{
	edge *e1=(edge*)t1;
	edge *e2=(edge*)t2;
	return distance(a[e2->id1],a[e2->id2])-distance(a[e1->id1],a[e1->id2]);
}
int main()
{
	int t,i,j,k,l;
	ull score=1;
	scanf("%d",&t);
	while(t--)
	{
		score=1;
		scanf("%d%d",&n,&d);
		for(i=0;i<n;i++)
		{
			a[i].marked=0;
			a[i].used=0;
			for(j=0;j<d;j++)
			{
				scanf("%d",&a[i].c[j]);	
			}
		}
		counter1=0;
		for(i=0;i<n;i++)
		{
			if(a[i].used)
				continue;
			else
			{
				for(j=i+1;j<n;j++)
				{
					if(a[i].used)
						continue;
					else
					{
						l=0;
						for(k=0;k<d;k++)
							if(a[i].c[k]==a[j].c[k])
								l++;
						if(l==d)
						{
							a[j].used=1;
							continue;
						}
						else
						{
							b[counter1].id1=i;					
							b[counter1].id2=j;							
							counter1++;
						}
					}
				}
			}
		}
		/*Have All the Edges
		  Need to run kruskals to get maximum spanning tree
		*/		
		qsort(b,counter1,sizeof(b),compare);
/*		for(i=0;i<counter1;i++)
		{
			printf("%lld\n",distance(a[b[i].id1],a[b[i].id2]));
		}*/
		for(i=counter1-1;i>=0;i--)
		{
			if((a[b[i].id1].used || a[b[i].id2].used) || (a[b[i].id1].marked && a[b[i].id2].marked))
				continue;
			else
			{
				score*=distance(a[b[i].id1],a[b[i].id2]);
				if(score>=MOD)
					score%=MOD;
				a[b[i].id1].marked=1;
				a[b[i].id2].marked=1;	
			}
		}
		printf("%lld\n",score);
	}
	return 0;
}

