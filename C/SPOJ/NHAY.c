#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,j=0,k,n,*p;
        char *a,b;
	int q=0;
	while(scanf("%d",&n) == 1)
	{
		a=(char*)malloc(sizeof(char)*(n+1));
		p=(int*)calloc(n,sizeof(int)*(n+1));
		getchar();
		gets(a);	
		p[0]=-1;p[1]=0;
		for(i=2,j=0;i<=n;i++)
		{
			if(a[i-1]==a[j])
				j++;
			else{ 
				j=p[j];
				if(j<0)
					j=0;
			}
			p[i]=j;
		}
		i=0,k=-1,q=0;
		while(1)
		{
			b = getchar();
			if(b == '\n')
				break;
			k++;
			if(b==a[i]){
				i++;
				if(i==n){
					printf("%d\n",k-i+1);
					i=p[i];
					q++;
				}
			}	
			else{
				while(i!=-1 && b!=a[i]) {
					i=p[i];
				}
				i++;
			}
		}
		if(q==0)
			printf("\n");
		free(a);
		free(p);
	}
	return 0;
}
