#include<stdio.h>
#include<stdlib.h>
int k,a[100],n;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
	int t,i,sum,q,e;
	scanf("%d",&t);
	while(t--)
	{
		sum=q=e=0;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		qsort(a,n,sizeof(int),compare);
		for(i=0;i<k;i++)
			q+=a[i],e+=a[n-i-1];
		if(abs(sum-2*q)>abs(sum-2*e))
			printf("%d\n",abs(-2*q+sum));
		else
			printf("%d\n",abs(-2*e+sum));
	}
	return 0;
}
