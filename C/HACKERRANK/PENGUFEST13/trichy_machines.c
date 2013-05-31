#include<stdio.h>
#define MAX 100000
#define ull unsigned long long int
ull count;
ull left[2*MAX],right[2*MAX];
int main()
{
	int f1,f2,n,p,a[MAX],i,j,k,l;
	scanf("%d%d",&n,&p);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==p)
		{
			l=i;
			count++;
		}
	}
	f1=0;
	for(i=l-1;i>=0;i--)
	{
		if(a[i]>p)
			f1--;
		else if(a[i]<p)
			f1++;
		else if(a[i]==p)
			f1=f1;
		if(f1<0)
			left[MAX+-f1]++;
		else
			left[f1]++;
	}
	left[MAX]=left[0];
	f1=0;
	for(i=l+1;i<n;i++)
	{
		if(a[i]>p)
			f1--;
		else if(a[i]<p)
			f1++;
		else if(a[i]==p)
			f1=f1;
		if(f1<0)
			right[MAX+-f1]++;
		else
			right[f1]++;
	}
	right[MAX]=right[0];
	for(i=0;i<MAX;i++)
	{
		count+=left[i]*right[MAX+i];
	}
	for(i=1;i<MAX;i++)
	{
		count+=left[MAX+i]*right[i];
	}
	count+=left[0];
	count+=right[0];
	printf("%lld\n",count);
	return 0;
}
