#include<stdio.h>
#define ull unsigned long long int
#define MOD 1000000007
ull fastpow(ull a,ull b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	ull temp=fast_pow(a,b/2);
	if(b%2)
		return((((temp*temp)%MOD)*a)%MOD);
	else
		return (temp*temp)%MOD;
}
int main()
{
	int t,n;
	ull temp,temp1=fastpow(25,MOD-2);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%2==0)
			temp=(((52*(fastpow(26,n/2)-1))%MOD)*temp1)%MOD;
		else
		{
			n--;
			temp=(((52*(fastpow(26,n/2)-1))%MOD)*temp1)%MOD;
			temp=((temp+fastpow(26,n/2+1)%MOD);
		}
		printf("%lld\n",temp);
		/*
		if(n%2==0)
		a=52
		r=26
		a*(r^n-1)/(r-1)
		else
			n--;
		26^(n/2+1)
		*/
	}
	return 0;
}
