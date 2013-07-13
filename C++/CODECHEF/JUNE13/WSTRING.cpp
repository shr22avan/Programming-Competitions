#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int t,v,max,l,hash[26],j,max1,max2,hash2[26],front[10000],back[10000],d[10000],middle[10000],counter;
	char a[10001];
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%s",a);
		memset(hash,0,sizeof(hash));
		l=strlen(a);
		max2=-1,max=counter=0;
		for(int i=0;i<l;i++)
		{
			if(a[i]!='#')
			{
				front[i]=middle[i]=-1;
				hash[a[i]-'a']++;
				hash2[a[i]-'a']++;
				if(hash[a[i]-'a']>max)
					max=hash[a[i]-'a'];
				if(hash2[a[i]-'a']>max2)
					max2=hash2[a[i]-'a'];
			}
			else
			{
				d[counter++]=i;
				middle[i]=max2;
				max2=-1;
				memset(hash2,0,sizeof(hash2));
				front[i]=max;
			}
		}
		memset(hash,0,sizeof(hash));
		max=0;
		for(int i=l-1;i>=0;i--)
		{
			if(a[i]!='#')
			{
				back[i]=-1;
				hash[a[i]-'a']++;
				if(hash[a[i]-'a']>max)
					max=hash[a[i]-'a'];
			}
			else
			{
				back[i]=max;
			}
		}
		max=v=max1=0;
		for(int j=0;j<counter-2;j++)
		{
//			cout<<"i:"<<d[j]<<":"<<front[d[j]]<<" m1:"<<middle[d[j+1]]<<" m2:"<<middle[d[j+2]]<<" e:"<<back[d[j+2]]<<"\n"; 
			v=front[d[j]];
			v+=middle[d[j+1]];
			v+=middle[d[j+2]];
			v+=back[d[j+2]];
			v+=3;
			if(v>max)
				max=v;
		}
		printf("%d\n",max);
	}
	return 0;
}
