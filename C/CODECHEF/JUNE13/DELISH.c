#include<stdio.h>
#include<stdlib.h>
#define ull long long int
#define MAX_SIZE 10000
#define MIN_INT -10000000001
#define getint(n) scanf("%lld",&n)
#define putint(d) printf("%lld\n",f)
/*ull abs(ull a)
{
	if(a<0) a=-a;
	return a;
}*/
int main()
{
	ull t,n,i,max1,max2,d[MAX_SIZE],dp1[MAX_SIZE],dp2[MAX_SIZE],dp3[MAX_SIZE],dp4[MAX_SIZE];
	getint(t);
	while(t--)
	{	
		getint(n);
		for(i=0;i<n;i++)
			dp1[i]=dp2[i]=dp3[i]=dp4[i]=0;	
		for(i=0;i<n;i++)
			getint(d[i]);

		max1=d[0];
		max2=d[0];
		dp1[0]=max2;
		for(i=1;i<n;i++)
		{
			if(max1<0)
				max1=d[i];
			else
				max1+=d[i];
			if(max2<max1)
				max2=max1;
			dp1[i]=max2;
		}

		max1=-d[n-1];
		max2=-d[n-1];
		dp2[n-1]=-max2;
		for(i=n-2;i>=0;i--)
		{
			if(max1<0)
				max1=-d[i];
			else
				max1+=-d[i];
			if(max2<max1)
				max2=max1;
			dp2[i]=-max2;	
		}

		max1=d[n-1];
		max2=d[n-1];
		dp3[n-1]=max2;
		for(i=n-2;i>=0;i--)
		{
			if(max1<0)
				max1=d[i];
			else
				max1+=d[i];
			if(max2<max1)
				max2=max1;
			dp3[i]=max2;
		}

		max1=-d[0];
		max2=-d[0];
		dp4[0]=-max2;
		for(i=1;i<n;i++)
		{
			if(max1<0)
				max1=-d[i];
			else
				max1+=-d[i];
			if(max2<max1)
				max2=max1;
			dp4[i]=-max2;
		}
	
		max1=-1;
		for(i=0;i<n-1;i++)
		{
			max2=abs(dp1[i]-dp2[i+1]);
			if(max2>max1)
				max1=max2;
		}
		for(i=0;i<n-1;i++)
		{
			max2=abs(dp4[i]-dp3[i+1]);
			if(max2>max1)
				max1=max2;
		}
		putint(max1);
	}
	return 0;
}
