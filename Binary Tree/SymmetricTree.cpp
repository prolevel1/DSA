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
bool func(node* &p, node* &q) {
	if (p == NULL && q == NULL) return true;
	if (p == NULL || q == NULL || p->val != q->val) return false;
	return func(p->left, q->right) && func(p->right, q->left);
}
bool isSymmetric(node* root) {
	return func(root->left, root->right);
}
int main() {
	struct node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);

	if( isSymmetric(root) == true) {
		cout << "symmetric";
	}
	else  {
		cout << "not";
	}
	return 0;
}