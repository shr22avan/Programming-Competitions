#include<iostream>
#include<cstdio>
#include<cstring>
#define ull unsigned long long int
#define MAX_SIZE 100
#define MAX_SUM 22500
using namespace std;
void swap(int &i1,int &i2)
{
	int a=i1;
	i1=i2;
	i2=a;
}
ull dp1[2][MAX_SUM],dp2[2][MAX_SUM];
int main()
{
	int t,n,a[MAX_SIZE],sum=0,sum1=0,k,i1=0,i2=1,sum2=0;
	scanf("%d",&t);
	while(t--)
	{
		i1=0,i2=1;
		memset(dp1[i1],0,sizeof(dp1[i1]));
		memset(dp2[i1],0,sizeof(dp2[i1]));
		sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(n==1)
		{
			printf("%d %d",0,a[0]);
			if(t)
				printf("\n\n");
			else
				printf("\n");
			continue;
		}
		for(int i=0;i<64 && i<n;i++)
		{
			if(!dp1[i1][a[i]])
				dp1[i1][a[i]]=1<<i;
		}
		for(int i=64;i<n;i++)
		{
			if(!dp2[i1][a[i]])		
				dp2[i1][a[i]]=1<<(i-64);
		}
		for(int i=2;i<=n/2+n%2;i++)
		{
			for(int j=1;j<=sum/2;j++)
			{
				dp1[i2][j]=dp2[i2][j]=0;
				k=0;
				while(dp1[i2][j]==0 && dp2[i2][j]==0 && k<n)
				{
					if(j-a[k]>=0)
					{
						if(k<=63)
						{
							if(!dp1[i1][j-a[k]] && !dp2[i1][j-a[k]])
								k++;
							else
							{
								if(dp1[i1][j-a[k]]&(1<<k))
									k++;
								else
								{
									dp1[i2][j]=dp1[i1][j-a[k]] | (1<<k);
									dp2[i2][j]=dp2[i1][j-a[k]];
									break;
								}
							}
						}
						else
						{
							if(!dp2[i1][j-a[k]] && !dp1[i1][j-a[k]])
								k++;
							else
							{
								if(dp2[i1][j-a[k]]&(1<<(k-64)))
									k++;
								else
								{
									dp1[i2][j]=dp1[i1][j-a[k]];
									dp2[i2][j]=dp2[i1][j-a[k]] | (1<<(k-64));
									break;
								}
							}

						}
					}
					else
						k++;
				}
			}
			swap(i1,i2);
		}
		sum1=0;
		swap(i1,i2);		
		for(int i=sum/2;i>=0;i--)
		{
			if(dp1[i2][i] || dp2[i2][i])
			{
				printf("%d %d",i,sum-i);
				if(t)
					printf("\n\n");
				else
					printf("\n");
				break;				
			}
			else if(n%2 && (dp1[i1][i] || dp2[i1][i]))
			{
				printf("%d %d",i,sum-i);			
				if(t)
					printf("\n\n");
				else
					printf("\n");
				break;
			}
		}
	}
	return 0;
}
