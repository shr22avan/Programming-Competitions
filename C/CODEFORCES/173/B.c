#include<stdio.h>
int main()
{
	int vetti,i,n,a[1000000],sum;
	scanf("%d",&n);
	sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&vetti);
		sum+=a[i];
	}
	vetti=500+1000*n-sum;
	vetti/=1000;
	if(vetti==0)
		printf("-1\n");
	else
	{
		for(i=0;i<vetti;i++)
			printf("A");
		for(i=0;i<n-vetti;i++)
			printf("G");
		printf("\n");
	}
	return 0;
}
