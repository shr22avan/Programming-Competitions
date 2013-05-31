#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ull unsigned long long int
ull MOD;
#define MAX_SIZE 20
void display(ull a[MAX_SIZE][MAX_SIZE],int k)
{
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			printf("%lld ",a[i][j]);
		}
		printf("\n");
	}
}
void matrix_multiply(ull a[MAX_SIZE][MAX_SIZE],ull b[MAX_SIZE][MAX_SIZE],int k,ull c[MAX_SIZE][MAX_SIZE])
{
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			c[i][j]=0;
			for(int p=0;p<k;p++)
			{
				c[i][j]+=((a[i][p]*b[p][j])%MOD);		
				if(c[i][j]>=MOD)
					c[i][j]%=MOD;
			}
		}
	}
}
void matrix_copy(ull a[MAX_SIZE][MAX_SIZE],ull b[MAX_SIZE][MAX_SIZE],int k)
{
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			a[i][j]=b[i][j];
}
void fast_power(ull a[MAX_SIZE][MAX_SIZE],int n,int k,ull ans[MAX_SIZE][MAX_SIZE])
{
	if(n==0)
	{
		memset(ans,0,sizeof(ans));
		for(int i=0;i<k;i++)
		{
			ans[i][i]=1;
		}
	}
	else if(n==1)
	{
		matrix_copy(ans,a,k);
	}
	else
	{
		ull ans1[MAX_SIZE][MAX_SIZE],ans2[MAX_SIZE][MAX_SIZE];
		fast_power(a,n/2,k,ans1);
		//	display(ans1,k);	
		if(n%2)
		{
			matrix_multiply(ans1,ans1,k,ans2);
			matrix_multiply(ans2,a,k,ans);
		}
		else
			matrix_multiply(ans1,ans1,k,ans);
	}
}
ull expo(int n,int k, ull big[MAX_SIZE][MAX_SIZE],ull b[MAX_SIZE])
{
	ull val,val2,answer[MAX_SIZE][MAX_SIZE];
	fast_power(big,n-k,k,answer);
	val=0,val2=0;
	for(int i=0;i<k;i++)
	{
		val2=((answer[0][i]*b[k-i-1]));
		if(val2>=MOD)
			val2%=MOD;
		val+=val2;
		if(val>=MOD)
			val%=MOD;
	}
	return val;
}
ull mod(ull a)
{
	if(a<0)
		a=MOD+a;
	else
		a%=MOD;
	return a;
}
int main()
{
	int C,k,m,n;
	ull b[MAX_SIZE],c[MAX_SIZE];
	ull val1,val2,big[MAX_SIZE][MAX_SIZE];
	scanf("%d",&C);
	memset(big,0,sizeof(big));	
	while(C--)
	{
		memset(big,0,sizeof(big));	
		scanf("%d",&k);
		for(int i=0;i<k;i++)
			scanf("%lld",&b[i]);
		val1=0;val2=0;
		for(int i=0;i<k;i++)
			scanf("%lld",&c[i]);
		for(int i=0;i<k;i++)
		{
			val1+=b[i];
			val2+=c[k-i-1]*b[i];
			b[i]=val1;
		}
		b[k]=val2;
		big[0][0]=c[0];
		for(int i=1;i<k;i++)
		{
			big[0][i]=c[i]-c[i-1];
		}
		big[0][k]=-c[k-1];
		for(int i=1;i<=k;i++)
		{			
			big[i][i-1]=1;
		}
		scanf("%d%d%lld",&m,&n,&MOD);
		if(n<=k)
			printf("%lld\n",b[n-1]-b[m-1]);
		else
		{
			if(m>k)
				val1=expo(m-1,k,big,b);
			else
				val1=b[m-2];
			cout<<val1<<endl;
			val2=expo(n,k,big,b);
			printf("%lld\n",mod(val2-val1));
		}
	}
	return 0;
}
