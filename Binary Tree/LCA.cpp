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
node* lca(node* &root, node* &p, node* &q) {
	if (root == NULL || root == p || root == q) return root;
	node* l = lca(root->left, p, q);
	node* r = lca(root->right, p, q);
	if (l == NULL) {
		return r;
	}
	else if (r == NULL) {
		return l;
	}
	else {
		return root;
	}
}
int main() {
	struct node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);

	struct node* p = new node(2);
	struct node* q = new node(3);

	struct node* temp = lca(root, p, q);
	cout << temp->val << "";
	return 0;
}