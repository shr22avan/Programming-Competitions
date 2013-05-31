#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX_LEN 200001
using namespace std;
int main()
{
	int t,n,k,l1,l2,hash[26];
	char a;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<26;i++)
			hash[i]=0;
		a='0';
		while(a!='\n')
		{
			a=getc(stdin);
			hash[a-'a']++;
		}
		a='0';
		while(a!='\n')
		{
			a=getc(stdin);
			hash[a-'a']++;
		}
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			a='0';
			while(a!='\n')
			{
				a=getc(stdin);
				hash[a-'a']--;
			}
		}
		for(k=0;k<26 && hash[k]>=0;k++);
		if(k==26)
			printf("YES\n");
		else
			printf("NO\n");
	}		
	return 0;
}
