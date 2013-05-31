#include<stdio.h>
int main()
{
	char a[52]="415926530119026040722614947737296840070086399613316";
	int t,k,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		printf("3");
		if(k)
		{
			if(k==1)
				printf(".1");
			else
			{
				k--;
				printf(".1");
				for(p=0;p<k/51;p++)
					printf("%s",a);
				for(p=0;p<k%51;p++)
					printf("%c",a[p]);
			}
		}
		printf("\n");
	}
	return 0;
}
