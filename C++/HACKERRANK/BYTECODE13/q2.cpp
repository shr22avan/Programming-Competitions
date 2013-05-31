#include<iostream>
#include<cstdio>
#define ull unsigned long long int
#define MOD 1000000007
using namespace std;
ull fast_pow(ull a,ull b)
{
	if(b==0)
		return 1;
	else if(b==1)
		return a;
	else
	{
		ull temp=fast_pow(a,b/2),temp1;
		temp1=temp*temp;
		if(temp1>=MOD)
			temp1%=MOD;
		if(b%2)
		{
			temp1=temp1*a;
			if(temp1>=MOD)
				temp1%=MOD;
			return temp1;
		}
		else
			return temp1;
	}
}
int main()
{
	ull t,n,val,b[8]={1,1,2,2,4,4,6,6};
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		n*=4;
		if(n>=8)
		{
			val=fast_pow(10,n/8)*b[n%8];			
			if(val>=MOD)
				val%=MOD;
		}
		else		
			val=b[n];
		printf("%lld\n",val);
	}
	return 0;
}
