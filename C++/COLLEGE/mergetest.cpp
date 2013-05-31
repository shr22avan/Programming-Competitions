#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
int main()
{
	int n=10000000;
	vector<int> data;
	data.resize(n);
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		data[i]=(rand()%10);
	}
	clock_t t=clock();
	sort(data.begin(),data.begin()+n);
	t=clock()-t;
	cout<<t<<endl;
	cout<<t/(double)CLOCKS_PER_SEC<<endl;
	return 0;
}

