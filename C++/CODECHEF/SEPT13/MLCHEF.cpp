#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

#define geti(a) scanf("%d",&a)
#define MAX 100000

using namespace std;

struct node {
	int health, superior;
};
vector<node> arr;
int main() {
	int n, a, b, q;
	node k;
	geti(n);
	for(int i = 0; i < n; i++) {
		geti(k.health);
		geti(k.superior);
		arr.push_back(k);
	}
	geti(q);
	while(q--) {
		geti(a);
		if(a == 1) {
			geti(a);
			geti(b);
			poison(a,b);
		}
		else {
			geti(a);
			a = query(a);
			printf("d\n",a);
		}
	}
	return 0;
}
