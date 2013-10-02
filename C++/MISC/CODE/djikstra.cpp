#include<iostream>
#include<queue>
#include<vector>
#define MAX 10000
#define MAX_V 30
using namespace std;
struct vertex{
	int index;
	int weight;
};
class comparator{
	public:
	bool operator() (const vertex &a, const vertex &b) {
		return a.weight > b.weight;
	}
};
int main() {
	
	int v, e, source = 0, destination = 5, index, weight_through;

	vector<int> weight(MAX_V, MAX);
	vector<bool> visited(MAX_V, false);
	vector< vector<vertex> > adj(MAX_V);
	priority_queue<vertex, vector<vertex>, comparator> pq;
	vertex temp;
	
	cin >> v;

	for(int i = 0; i < v; i++) {
		cin >> e;
		for(int j = 0; j < e; j++) {
			cin >> temp.index;
			cin >> temp.weight;
			adj[i].push_back(temp);
		}
	}
	cin >> source >> destination;

	weight[source] = 0;
	visited[source] = true;
	while(source != destination) {
		for(int i = 0; i < adj[source].size(); i++) {
			index = adj[source][i].index;
			weight_through = adj[source][i].weight + weight[source];
			if((weight_through < weight[index]) && !visited[index])
			{
				weight[index] = weight_through;
				temp.index = index;
				temp.weight = weight[index];
				pq.push(temp);
			}
			visited[source] = true;
		}
		temp = pq.top();
		pq.pop();
		source = temp.index;
	}

	cout << temp.weight << endl;

	//adj.assign(MAX_V);
	//weight.assign(MAX_V,MAX);
	return 0;
}
