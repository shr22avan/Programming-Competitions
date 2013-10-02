#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
#define getint(a) scanf("%d",&a)
int main() {
	string s;
	cin>>s;
	int a1=0,a2=0,a3=0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i]=='+')
			continue;
		else {
			if(s[i]=='1')
				a1++;
			if(s[i]=='2')
				a2++;
			if(s[i]=='3')
				a3++;
		}
	}
	for(int i = 0; i < a1-1; i++) {
		cout<<"1+";
	}
	if((a2!=0 || a3!=0) && a1!=0)
		cout<<"1+";
	else if(a1!=0)
		cout<<"1";
	for(int i = 0; i < a2-1; i++) {
		cout<<"2+";
	}
	if(a3!=0 && a2!=0)
		cout<<"2+";
	else if(a2!=0)
		cout<<"2";
	for(int i = 0; i < a3-1; i++) {
		cout<<"3+";
	}	
	if(a3!=0)
		cout<<"3"; 
	return 0;
}
