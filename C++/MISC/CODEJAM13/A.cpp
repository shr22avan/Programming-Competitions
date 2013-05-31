#include<iostream>
#include<cstdio>
using namespace std;
char a[4][4];
int check()
{
	int counto,countx,countt,countd=0;
	for(int i=0;i<4;i++)
	{
		counto=countx=countt=0;
		for(int j=0;j<4;j++)
		{
			if(a[i][j]=='X')
				countx++;
			else if(a[i][j]=='O')
				counto++;
			else if(a[i][j]=='T')
			{
//				cout<<"T"<<endl;
				countt++;		
			}
		}
//		cout<<countx<<":"<<counto<<":"<<countt<<endl;
		if(countx==4 || (countx==3 && countt==1))
			return 1;
		else if(counto==4 || (counto==3 && countt==1))
			return 2;
	}	
	for(int i=0;i<4;i++)
	{
		counto=countx=countt=0;
		for(int j=0;j<4;j++)
		{
			if(a[j][i]=='X')
				countx++;
			else if(a[j][i]=='O')
				counto++;
			else if(a[j][i]=='T')
				countt++;		
		}			
		if(countx==4 || (countx==3 && countt==1))
			return 1;
		else if(counto==4 || (counto==3 && countt==1))
			return 2;
	}
	counto=countx=countt=0;	
	for(int i=0;i<4;i++)
	{
		if(a[i][i]=='X')
			countx++;
		else if(a[i][i]=='O')
			counto++;
		else if(a[i][i]=='T')
			countt++;		
	}	
	if(countx==4 || (countx==3 && countt==1))
		return 1;
	else if(counto==4 || (counto==3 && countt==1))
		return 2;
	counto=countx=countt=0;		
	for(int i=0;i<4;i++)
	{
		if(a[i][3-i]=='X')
			countx++;
		else if(a[i][3-i]=='O')
			counto++;
		else if(a[i][3-i]=='T')
			countt++;		
	}	
	if(countx==4 || (countx==3 && countt==1))
		return 1;
	else if(counto==4 || (counto==3 && countt==1))
		return 2;
	countd=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j]=='.')
				countd++;
		}
	}
	if(countd==0)
		return 4;
	else
		return 3;
}
int main()
{
	int t,q;
//	scanf("%d",&t);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
		//		scanf("%c",&a[i][j]);
				cin>>a[i][j];
		}
		q=check();		
		if(q==1)
			printf("Case #%d: X won\n",k);
		else if(q==2)
			printf("Case #%d: O won\n",k);		
		else if(q==3)
			printf("Case #%d: Game has not completed\n",k);
		else
			printf("Case #%d: Draw\n",k);
	}
	return 0;
}
