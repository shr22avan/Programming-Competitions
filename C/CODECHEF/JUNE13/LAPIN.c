#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define getint(n) scanf("%d",&n);
int main()
{
	int t,hash[26],l,i,j,k;
	char s[10001];
	getint(t);
	while(t--)
	{
		memset(hash,0,sizeof(hash));
		scanf("%s",s);
		l=strlen(s);
		for(i=0;i<l/2;i++)
			hash[s[i]-'a']++;
		for(i=l/2+l%2;i<l;i++)
			hash[s[i]-'a']--;
		for(i=0;i<26;i++)
		{
			if(hash[i]!=0)
			{
				printf("NO\n");
				break;
			}
		}
		if(i==26)
			printf("YES\n");
	}
	return 0;
}
