#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,j=0,k,n,*p;
	char *a,b;
	scanf("%d",&n);
	a=(char*)malloc(sizeof(char)*(n+1));
	p=(int*)calloc(n,sizeof(int));
	scanf("%s",a);
	
	while(!feof(stdin))
	{
		scanf("%c",&b);
		j++;		
	}
	free(a);
	free(p);
	return 0;
}
