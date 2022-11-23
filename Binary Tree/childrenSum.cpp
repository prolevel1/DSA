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
void sumProperty(node* root) {
	int child = 0;
	if (root->left) {
		child += root->left->val;
	}
	if (root->right) {
		child += root->right->val;
	}
	if (child < root->val) {
		if (root->left) root->left->val = root->val;
		if (root->right) root->right->val = root->val;
	}
	sumProperty(root->left);
	sumProperty(root->right);
	int total = 0;
	if (root->left) total += root->left->val;
	if (root->right) total += root->right->val;
	if (root->left || root->right) root->val = total;

}

// TC - O(N)  SC - O(N)