#include<stdio.h>
#include<string.h>
#define MAX_LEN 200001
int main()
{
	int t,n,i,j,l,l1,l2,hash[26];
	char a[MAX_LEN],b[MAX_LEN],c[MAX_LEN];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		scanf("%s",b);
		l1=strlen(a);
		l2=strlen(b);
		memset(hash,0,sizeof(hash));
		for(i=0;i<l1;i++)
			hash[a[i]-'a']++;
		for(i=0;i<l2;i++)
			hash[b[i]-'a']++;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			for(j=0;j<strlen(c);j++)
				hash[c[j]-'a']--;	
		}
		for(i=0;i<26 && hash[i]>=0;i++);
		if(i==26)
			printf("YES\n");
		else
			printf("NO\n");
	}		
	return 0;
}
