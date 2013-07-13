#include<cstdio>
#include<queue>
#include<cstring>
#define getint(n) scanf("%d",&n)
#define emptyq(q) while(!q.empty()) q.pop()

using namespace std;
struct object {
	int number;
	int depth;
};

int main()
{
	int t,a,b,composite[10001];
	object temp,ttemp;
	queue<object> q;
	getint(t);
	memset(composite,0,sizeof(composite));
	composite[0]=0;
	composite[1]=0;
	composite[2]=0;
	composite[3]=0;
	for(int i=2;i<=100;i++)
		if(!composite[i])
			for(int j=2*i;j<=10000;j+=i)
				composite[j]=1;
	while(t--)
	{
		getint(a);
		getint(b);
		temp.number=a;
		temp.depth=0;
		q.push(temp);
	        while(!q.empty())
		{
			temp=q.front();
			q.pop();
			if(temp.number==b)
			{
				printf("%d\n",temp.depth);
				break;    
			}
			for(int i=1;i<=1000;i*=10)
			{
				if(i<1000)
				{
					for(int j=temp.number;j<=(temp.number/i*10)*(i*10)+i*10 && j<10000;j+=i)
					{
						if(!composite[j])
						{
							ttemp.number=j;
							ttemp.depth=temp.depth+1;
							q.push(ttemp);
						}
					}
				}
				else
				{
					for(int j=temp.number;j<10000;j+=i)
					{
						if(!composite[j])
						{
							ttemp.number=j;
							ttemp.depth=temp.depth+1;
							q.push(ttemp);
						}
					}

				}
			}
		}	
		if(q.empty())
			printf("Impossible\n");
		else
			emptyq(q);
	}
	return 0;
}
