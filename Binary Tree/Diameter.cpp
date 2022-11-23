#include<bits/stdc++.h>
using namespace std;
struct node {
	int val;
	struct node *left, *right;
	node(int data) {
		val = data;
		left = right = NULL;
	}
};
int func(node* &root, int &diam) {
	if (!root) return 0;
	int lh = func(root->left, diam);
	int rh = func(root->right, diam);
	diam = max(diam, lh + rh);
	return 1 + max(lh, rh);
}
int diameter(node* root) {
	
	int diam = 0;
	func(root, diam);
	return diam;
}

int main() {
	struct node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);

	cout << diameter(root);
	return 0;
}

//TC :: O(N) SC- O(H)