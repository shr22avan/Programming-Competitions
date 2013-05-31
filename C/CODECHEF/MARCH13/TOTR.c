#include<stdio.h>
int main()
{
	int t,i;
	char m[27],a[101];
	scanf("%d",&t);
	getchar();
	scanf("%s",m);	
	while(t--)
	{
		scanf("%s",a);
		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]=='_')
				a[i]=' ';
			else if(a[i]>='A' && a[i]<='Z')
				a[i]=m[a[i]-'A']-'a'+'A';
			else if(a[i]>='a' && a[i]<='z')
				a[i]=m[a[i]-'a'];
		}		
		printf("%s\n",a);
	}
	return 0;
}
