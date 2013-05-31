#include<iostream>
#include<cstdio>
#include<cstring>
#define ull unsigned long long int
#define MAX_SIZE 100
#define MAX_SUM 45000
using namespace std;
void swap(int &i1,int &i2)
{
	int a=i1;
	i1=i2;
	i2=a;
}
int abs1(int a)
{
	if(a>=0)
		return a;
	else
		return -a;
}
struct object
{
	int v;
	ull mask;
};
struct object1
{
	int h;
	int test;
};
object dp1[2][MAX_SUM],dp2[2][MAX_SUM];
int counter[2];
object1 hash[MAX_SUM];
int main()
{
	int t,n,a[MAX_SIZE],sum=0,s1=0,k,i1=0,i2=1,s2=0,s3;
	scanf("%d",&t);
	memset(hash,0,sizeof(hash));
	for(int e=1;e<=t;e++)
	{
		
		i1=0,i2=1;
		counter[i1]=counter[i2]=0;
		sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			if(i<64)
			{
				dp1[i1][counter[i1]].mask=1<<i;
				dp2[i1][counter[i1]].mask=0;				
			}
			else
			{
				dp1[i1][counter[i1]].mask=0;			
				dp2[i1][counter[i1]].mask=1<<(i-64);
			}
			dp1[i1][counter[i1]].v=a[i];
			dp2[i1][counter[i1]].v=a[i];			
			if(hash[a[i]].test!=e)
			{
				hash[a[i]].h=1;
				hash[a[i]].test=e;
				counter[i1]++;
			}
		}		
		if(n==1)
		{
			printf("%d %d",0,a[0]);
			if(e!=t)
				printf("\n\n");
			else
				printf("\n");
			continue;
		}
		for(int j=2;j<=n/2;j++)
		{
			counter[i2]=0;
			for(int k=0;k<counter[i1];k++)
			{
				for(int p=0;p<n;p++)
				{
					if(p<64)
					{
						if(!(dp1[i1][k].mask & (1<<p)))
						{
							dp1[i2][counter[i2]].mask=dp1[i1][k].mask|(1<<p);
							dp2[i2][counter[i2]].mask=dp2[i1][k].mask;
							dp1[i2][counter[i2]].v=dp1[i1][k].v+a[p];
							dp2[i2][counter[i2]].v=dp2[i1][k].v+a[p];
							if(hash[dp2[i2][counter[i2]].v].test!=e || (hash[dp2[i2][counter[i2]].v].test==e && hash[dp2[i2][counter[i2]].v].h!=j)){					
								hash[dp2[i2][counter[i2]].v].h=j;
								hash[dp2[i2][counter[i2]].v].test=e;					
								counter[i2]++;		
							}
						}
					}
					else
					{
						if(!(dp2[i1][k].mask & (1<<(p-64))))
						{
							dp1[i2][counter[i2]].mask=dp1[i1][k].mask;
							dp2[i2][counter[i2]].mask=dp2[i1][k].mask|(1<<(p-64));
							dp1[i2][counter[i2]].v=dp1[i1][k].v+a[p];
							dp2[i2][counter[i2]].v=dp2[i1][k].v+a[p];					
							if(hash[dp2[i2][counter[i2]].v].test!=e || (hash[dp2[i2][counter[i2]].v].test==e && hash[dp2[i2][counter[i2]].v].h!=j)){					
								hash[dp2[i2][counter[i2]].v].h=j;
								hash[dp2[i2][counter[i2]].v].test=e;					
								counter[i2]++;		
							}				
						}					
					}
				}
			}
			swap(i1,i2);
		}
		swap(i1,i2);
		s1=s2=s3=2*MAX_SUM;		
		for(int i=0;i<counter[i2];i++)
		{
			if(abs1(sum-2*dp1[i2][i].v)<s3)
			{
				s3=abs1(sum-2*dp1[i2][i].v);
				s1=dp1[i2][i].v;
				s2=sum-s1;
			}
		}
		if(s1<s2)
			printf("%d %d",s1,s2);
		else
			printf("%d %d",s2,s1);
		if(e!=t)
			printf("\n\n");
		else
			printf("\n");
	}
	return 0;
}
