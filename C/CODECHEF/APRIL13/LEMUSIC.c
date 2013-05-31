/* Gonna use map STL in C++*/
#include<stdio.h>
#define MAX_SIZE 100000
typedef struct object {
	int l,b;
} object;
object a[MAX_SIZE];
int compare(const void *a, const void *b)
{
	return (((object*)a)->l-((object*)b)->l);
}
int main()
{
	int t,n,i,j,k,l;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&j,&k);
			a[i].b=j;
			a[i].l=k;
		}
		qsort(a,n,sizeof(object),compare);
		for(	
	}
	return 0;
}
