#include<iostream>
#include<cstdio>
void dfs(int i)
{
	if(i>0)
	{
		if(i>1)
		{
			for(int j=1;j<=450;j++)
			{
				printf("%d ",j);
				dfs(i-1);
			}
		}
		else
		{
			for(int j=1;j<=450;j++)
			{
				printf("%d\n",j);
				dfs(i-1);
			}	
		}
	}
	else
		printf("\n");
}
int main()
{
	for(int i=1;i<=2;i++)
	{
		printf("%d\n",i);
		dfs(i);
	}	
	return 0;
}
