#include<iostream>
#include<string>
#include<cstring>
#include<queue>

#ifndef ALPHABETS
#define ALPHABETS 26
#endif

#ifndef F_ALPHA
#define F_ALPHA 'a'
#endif
using namespace std;
class suffix_trie {

	private:
	class node {
		node *next[ALPHABETS];
		int depth[ALPHABETS];
		node *backtrack;
		public:	
		node() {
			backtrack = 0;
			memset(next, 0, sizeof(next));
			memset(depth,0,sizeof(depth));
		}	
		int get_alpha_index(char a) {
			return (a - F_ALPHA);
		}	
		void set_next(node *ptr, char inserted)
		{
			int index = get_alpha_index(inserted);
			next[index] = ptr;
		}
		node* get_next(char next_char) {
			int index = get_alpha_index(next_char);
			return next[index];
		}
		void set_depth(char alphabet, int d) {
			int index = get_alpha_index(alphabet);
			depth[index] = d;
		}
		int get_depth(char alphabet) {
			int index = get_alpha_index(alphabet);
			return depth[index];	
		}
		char get_max_depth(){
			/* O(ALPHABET) search for maximum depth node. Requires improvement */
			int max_d = -1, max_i;
			for(int i = 0; i<ALPHABETS; i++)	{
				if(depth[i] > max_d) {
					max_i = i;
				}
			}
			return max_i + F_ALPHA;
		}
		void set_backtrack(node *ptr) {
			backtrack = ptr;
		}
		node* get_backtrack() {
			return backtrack;
		}
	};

	node* root, *deepest_leaf;
	node* new_node() {
		return new node;
	}

	public:
	void insert(char a) {
		if(root == 0) {
			root = new_node();
			root -> set_backtrack(NULL);
			node *temp = new_node();
			temp -> set_backtrack(root);
			root ->	set_next(temp, a);
			deepest_leaf = temp;
		}
		else {
			node *old = NULL, *temp = NULL, *invariant = deepest_leaf;
			while(invariant != NULL) {
				if(invariant -> get_next(a) == NULL) {
					temp = new_node();
					if(old)
						old -> set_backtrack(temp);
					old = temp;
					invariant -> set_next(temp, a);
					invariant = invariant -> get_backtrack();	
				}
				else {
					if(old)
						old -> set_backtrack(invariant -> get_next(a));
					old = NULL;
					invariant = invariant -> get_backtrack();
				}	
			}
			if(root -> get_next(a) == old)
				old -> set_backtrack(root);
			deepest_leaf = deepest_leaf -> get_next(a);	
		}
	}
	suffix_trie(string a) {
		root = deepest_leaf = NULL;
		for(int i = 0; i < a.length(); i++) {
			insert(a[i]);
		}
	}
	bool search(string a) {
		bool flag = true;
		node *traverser = root;
		for(int i = 0; i < a.length() && flag; i++) {
			if(traverser == NULL) {
				flag = false;
				continue;
			}
			else {
				traverser = traverser -> get_next(a[i]);
			}
		}
		if(traverser == NULL) {
			flag = false;
		}
		return flag;
	}
	void display() {
		queue <node*> q;
		q.push(root);
		node *temp;
		while(!q.empty()) {
			temp = q.front();
			q.pop();
			cout << "\nNew Node . . . .\n";
			for(int i = 0; i < ALPHABETS; i++) {
				if(temp -> get_next(i + F_ALPHA)) {
					q.push(temp -> get_next(i + F_ALPHA));
					cout << i + F_ALPHA << " ";
				}
			}
		}	
	}
};
int main() {
	string a,b;
	int t;
	cin >> a;
	suffix_trie trie(a);
	cin >> t;
	while(t--) {
		cin >> b;
		if(trie.search(b)) 
			cout << "Present.\n";
		else
			cout << "Not Present.\n"; 
	} 
	//trie.display();
	return 0;
}
