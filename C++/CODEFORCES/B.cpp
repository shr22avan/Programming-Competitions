#include<iostream>
#include<cstdio>
#include<cstdlib>
#define getint(a) scanf("%d",&a)
using namespace std;
int a[100001];

int modulo(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

bool Miller(long long p,int iteration=5){
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
	int n,i,k;
	getint(n);
	a[0]=2;
	for(k=1;k<n;k++)
	{
		for(long long int j=a[k-1]+1;j<=10000000;j++)
		{
			if(Miller(j)){
				a[k]=j;
				break;
			}
		}
	}
	for(i=0;i<n-1;i++)
	{
		printf("%d ",a[i]);
	}	
	printf("%d\n",a[n-1]);
	return 0;
}
