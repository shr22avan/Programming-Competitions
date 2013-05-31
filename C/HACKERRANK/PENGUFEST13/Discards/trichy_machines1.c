/*uses a n^2 dp possible in a little less . . . Discarding*/
#include<stdio.h>
#define MAX 100000
#define ull unsigned long long int
int dp[2][MAX];
ull count;
void swap(int* a,int* b)
{
	int c=*a;
	*a=*b;
	*b=c;
}
int main()
{
	int f1,f2,n,p,a[MAX],i,j,k,l;
	scanf("%d%d",&n,&p);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==p)
			l=i;
	}
	f1=0;f2=1;
	dp[f1][l]=0;
	count++;
	for(i=2;i<=n;i++)
	{
		for(j=l-i+1;j<l && j+i-1<n;j++)
		{
			if(j>=0)
			{
				if(a[j]<p)
					dp[f2][j]=dp[f1][j+1]+1;
				else if(a[j]>p)
					dp[f2][j]=dp[f1][j+1]-1;
				else if(a[j]==p)
					dp[f2][j]=dp[f1][j+1];
				if(i%2 && dp[f2][j]==0)
					count++;
			}
			else
				j=-1;
		}
		if(l+i-1<n)
		{
			if(a[l+i-1]<p)
				dp[f2][l]=dp[f1][l]+1;
			else if(a[l+i-1]>p)
				dp[f2][l]=dp[f1][l]-1;
			else if(a[l+i-1]==p)
				dp[f2][l]=dp[f1][l];
			if(i%2 && dp[f2][l]==0)
				count++;
		}
		swap(&f1,&f2);
	}
	printf("%lld\n",count);
	return 0;
}
