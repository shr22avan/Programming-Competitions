#include<stdio.h>
int primes[10001],counts[10001];
int main()
{
	int t,n,i,j,k,l,prime[1229],counter=0;
	primes[2]=primes[3]=0;
	primes[1]=1;
	for(i=2;i<=100;i++)
	{
		for(j=2*i;j<=10000 &&!primes[i];j+=i)
			primes[j]=1;
	}
	for(i=2;i<=10000;i++)
	{
		if(primes[i]==0)
		{
			prime[counter]=i;
			counter++;
		}
	}
	for(i=0;i<counter;i++)
	{
		for(j=0;j<counter;j++)
		{
			if(prime[i]+2*prime[j]<=10000)
				counts[prime[i]+2*prime[j]]++;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n<=5)
			printf("0\n");
		else
		{
			printf("%d\n",counts[n]);
		}
	}
	return 0;
}
