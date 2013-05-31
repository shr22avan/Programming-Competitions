#include<stdio.h>
#include<stdlib.h>
#define ull unsigned long long int
#define MOD 1000000007
ull fpow(int a,int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return a;
	else
	{
		ull temp=fpow(a,n/2);		
		if(n%2)
			return (((temp*temp)%MOD)*a)%MOD;
		else
			return (temp*temp)%MOD;
	}
}
int main()
{
	int t,n,m,k,i;
	ull val=0;
	ull inverse[100001],factorial[300001];
	factorial[0]=1;
	for(i=1;i<=300000;i++)
	{
		factorial[i]=factorial[i-1]*i;
		if(factorial[i]>MOD)
			factorial[i]%=MOD;
	}
	inverse[0]=0;
	inverse[1]=1;
	for(i=2;i<=100000;i++)
	{
		inverse[i]=inverse[i-1]*fpow(i,MOD-2);
		if(inverse[i]>MOD)
			inverse[i]%=MOD;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		val=factorial[n+m+k];
		val*=inverse[n];
		if(val>=MOD)
			val%=MOD;
		val*=inverse[m];
		if(val>=MOD)
			val%=MOD;
		val*=inverse[k];
		if(val>=MOD)
			val%=MOD;
		printf("%lld\n",val);
	}
	return 0;
}
