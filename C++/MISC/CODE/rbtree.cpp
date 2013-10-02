#include<iostream>
using namespace std;
struct node {
	int key;
	node *parent, *left, *right;
	bool RED;
	node() {
		parent = left = right = NULL;
		RED = true;
	}
} *root = NULL;
node* new_node() {
	return new node;
}
void blacken(node *parent) {
	if(parent -> left && parent -> right) {
		if(parent -> left -> RED && parent -> right -> RED) {
			parent -> left -> RED = parent -> right -> RED = false;
			parent -> RED = !(parent -> RED);
		}
	}
}

void two_rotate_left(node *grandparent) {
	node *parent = NULL, *temp = NULL;
	parent = grandparent -> left;
	temp = parent -> right;
	grandparent = temp;
	parent -> right = temp -> left;
	temp -> left = parent;
}

void two_rotate_right(node *grandparent) {
	node *parent = NULL, *temp = NULL;
	parent = grandparent -> right;
	temp = parent -> left;
	grandparent = temp;
	parent -> left = temp -> right;
	temp -> right = parent;
}

void rotate_left(node *greatgrandparent, bool left) {	
	node *grandparent, *parent, *temp = NULL, *aux = NULL;
	if(greatgrandparent == NULL)
		grandparent = root;
	else {
		if(left == true)
			grandparent = greatgrandparent -> left;
		else
			grandparent = greatgrandparent -> right;
	}
	parent = grandparent -> right;
	
	bool right = false;
	if(parent -> right)
		temp = parent -> right, right = true;
	else
		temp = parent -> left;
	
	if(right) {
		aux = parent;
		if(parent -> left) {
			grandparent -> right = parent -> left;
			parent -> left = NULL;
		}
		parent -> left = grandparent;
	}
	else {
		aux = temp;

	}
	
}
void insert(int key) {
	node *temp = new_node(), *grandparent = root, *parent = root, *traverser = root;
	temp -> key = key;
	bool movement, rotate = false;
	if(root == NULL) {
		root = temp;
		root -> RED = false;
	}
	else {
		while(traverser != NULL) {
			/* Assuming no equal key case */
			grandparent = parent;
			parent = traverser;
			if(temp -> key < traverser -> key)
				traverser = traverser -> left, movement = false;
			else
				traverser = traverser -> right, movement = true;
		}
		if(!movement)
			parent -> left = temp; 
		else
			parent -> right = temp;
			
		if(parent.RED)
			rotate = true;
	}
}
