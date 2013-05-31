#include<stdio.h>
#define ull unsigned long long int
#define MAX_SIZE 100000
int a[MAX_SIZE],best,m,k,sum;
int possible(int z)
{
	int i,count=0,s=0;
	for(i=0;i<m;i++)
	{
		s+=a[i];
		if(s>z)
		{
			count++;
			s=a[i];
		}
	}
	count++;
	return count;
}
void binary_search(int low,int high)
{
	int mid,val;
	while(low<=high)
	 {
		mid=(low+high)/2;
		val=possible(mid);
		if(val<=k)
		{
			if(val==k)
				best=mid;
			high=mid-1;	
		}
		else
		{
			low=mid+1;
		}
	}
}
void possibility(int z)
{
        int i,count=0,s=0;
        for(i=0;i<m;i++)
        {
                s+=a[i];
                if(s>z)
                {
			printf("/ ");
                        count++;
                        s=a[i];
                }
		if(i<m-1)
			printf("%d ",a[i]);
		else
			printf("%d\n",a[i]);
        }
        count++;
}

/*void possibility(int z)
{
        int i,count=0,s=0,e[500],top=-1;
        for(i=m-1;i>=0;i--)
        {
                s+=a[i];
                if(s>z)
                {
                        s=a[i];
			e[++top]=-1;
                }
		e[++top]=a[i];
        }
	for(i=0;i<top;i++)
	{
		if(e[i]!=-1)
		{
			if(i!=(top-1))
				printf("%d ",e[i]);
			else
				printf("%d",e[i]);
		}
		else
			printf("/ ");
	}
}*/
int main()
{
	int n,i,val;
	scanf("%d",&n);
	while(n--)
	{
		sum=0;best=-1;
		scanf("%d%d",&m,&k);
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		binary_search(0,sum);
		possibility(best);
	}	
	return 0;
}
