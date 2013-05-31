#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define ull1 long long
using namespace std;
int modulo(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y);
            if(x>=c)
            	x%=c;
        }
        y = (y*y);
        if(y>=c)
        	y%=c; // squaring the base
        b /= 2;
    }
    return x;
}
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y);
            if(x>=c)
            	x%=c;
        }
        y = (y*2);
        if(y>=c)
        	y%=c;
        b /= 2;
    }
    return x;
}

bool Miller(long long p,int iteration=30){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}
int main()
{
	ull1 n,j;
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&n);
		n-=((n%2)==0);
		for(j=n;j>1;j--)
		{
			if(j==2 || j==3 || j==5 || j==7 || j==11)
			{
				printf("%lld\n",j);
				break;
			}
			if(j%2==0 ||j%3==0 ||j%5==0 ||j%7==0 ||j%11==0)
				continue;
			if(Miller(j))	
			{
				printf("%lld\n",j);
				break;
			}
			
		}
	}	
	return 0;
}
