#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#define ARR_SIZE 100000
#define MIN 0
#define MAX 100000000
int a[ARR_SIZE];
using namespace std;
struct object
{
	int m2,m1;
	object()
	{
		m2=MAX;
		m1=MIN;
	}
	void display()
	{
		cout<<m2<<":"<<m1<<endl;
	}
};
int max1(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int min1(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
struct min_max_seg_tree
{
	object b[3*ARR_SIZE];
	int size;
	object useless;
	min_max_seg_tree(int n)
	{
		useless.m2=-1,useless.m1=-1;
		size=ceil(log2(n))+1;
		size=pow(2,size);
	}
	void display()
	{
		for(int i=0;i<size;i++)
		{
//			cout<<b[i].m1<<":"<<b[i].m2<<endl;
		}
	}
	void initialize(int node, int l, int u)
	{
		if(l==u)
		{
			b[node].m1=(a[l]);
			b[node].m2=(a[l]);					
		}
		else if(l<u)
		{
			int mid=(l+u)/2;
			initialize(2*node+1,l,mid);
			initialize(2*node+2,mid+1,u);
			/*Check the property here*/
			b[node].m1=max1(b[2*node+1].m1,b[2*node+2].m1);
			b[node].m2=min1(b[2*node+1].m2,b[2*node+2].m2);			
		}
	}
	object query(int node,int l, int u,int lr,int ur)
	{
//		cout<<l<<":"<<u<<":"<<lr<<":"<<ur<<endl;
		if(ur<l || lr>u)
			return useless;
		if(lr<=l && ur>=u)
		{
			/*This case occurs when the node range fits into the queried range
			  1)return node's value;
			*/
//				cout<<b[node].m1<<":"<<b[node].m2<<endl;
				return b[node];
		}
		else
		{
			/*This situation occurs when the node's range min1us queried range is not 0
			  Recursively Call query into the node's children
			*/
			int mid;
			object val1,val2;
			mid=(l+u)/2;
			val1=query(2*node+1,l,mid,lr,ur);
			val2=query(2*node+2,mid+1,u,lr,ur);			
			b[node].m1=max1(b[2*node+1].m1,b[2*node+2].m1);
			b[node].m2=min1(b[2*node+1].m2,b[2*node+2].m2);			
			if(val1.m1!=-1)
			{
				if(val2.m1!=-1)
				{
					val1.m1=max1(val1.m1,val2.m1);
					val1.m2=min1(val1.m2,val2.m2);
					return val1;
				}
				else 
					return val1;
			}
			else
			{
				if(val2.m1!=-1)
					return val2;
				else
					return useless;
			}
		}
	}	
};
int main()
{
	int n,q,k,b,c;
	float val,val1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	min_max_seg_tree tree(n);
	tree.initialize(0,0,n-1);
	object o1,o2,o3;
	tree.display();
	while(q--)
	{
		scanf("%d%d",&b,&c);
		o1=tree.query(0,0,n-1,b,c);
		o2=tree.query(0,0,n-1,0,b-1);		
		o3=tree.query(0,0,n-1,c+1,n-1);	
		val=o1.m2;
		val1=(o1.m1*1.0-val)/2.0;
		if(o2.m2!=-1)
		{
			if(o2.m1>val1)
				val1=o2.m1;
		}	
		if(o3.m2!=-1)
		{
			if(o3.m1>val1)
				val1=o3.m1;
		}
		val+=val1;
		printf("%0.1f\n",val);
	}
	return 0;
} 
