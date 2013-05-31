/*n^n-2 tree cayley's theorem
k=1
n^n-2
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#define MOD 1000000007
#define ull unsigned long long int
ull fast_power(int a,int b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	else
	{
		ull temp=fast_power(a,b/2);
		temp*=temp;
		if(temp>=MOD)
			temp%=MOD;
		if(b&2)
			temp*=a;
		if(temp>=MOD)
			temp%=MOD;
	}
}
ull mod_inverse(int k,int p)
{
	return fast_power(k,p-2);
}
ull C(int n,int r)
{
	if(r==0 || r==n)
		return 1;
	if(r==1 || r==n-1)
		return n;
	if(r>n-r)
		r=n-r;
	ull val=1;
	for(int k=n;k<n-r;k--)
	{
		val*=k;
		if(val>=MOD)
			val%=MOD;
	}
	for(int k=r;k>0;k--)
	{
		val*=mod_inverse(k,MOD);
		if(val>=MOD)
			val%=MOD;
	} 
}
using namespace std;
int main()
{
	int n,k,z;
	ull val,val1;
	scanf("%d%d",&n,&k);
	n*=k;
	val=fast_power(n,n-2);	
	if(k==2)
	{
/*k=2
val=n^(n-2)
z=n/2
val=val-(zC1)*((n-1)^(n-3))+zC2*(n-2)^(n-4) . . .. */
		z=n/2;
		for(int i=1;i<=z;i++)
		{
			val1=C(z,i)*fast_power(n-i,n-i-2);
			if(val1>=MOD)
				val1%=MOD;
			if(i&1)
				val-=val1;
			else
				val+=val1;
		}
	}
	else if(k==3)
	{
/*	val=n^(n-2)
	z=n/3
	val=val-(zC1)*((n-2)^(n-4))+zC2*(n-4)^(n-6) . . .. . . .*/
		z=n/3;
		for(int i=1;i<=z;i++)
		{
			val1=C(z,i)*fast_power(n-2*i,n-2*i-2);
			if(val1>=MOD)
				val1%=MOD;
			if(i&1)
				val-=val1;
			else
				val+=val1;
		}

	}
	printf("%lld\n",val);
	return 0;
}
