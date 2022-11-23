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
void levelOrder(node* root) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		int n = q.size();
		for (int i = 0; i < n; i++) {
			node *temp = q.front();
			q.pop();
			cout << temp->val << " ";
			if (temp->left != NULL) {
				q.push(temp->left);
			}
			if (temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
}
int main() {
	struct node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);

	levelOrder(root);
	return 0;
}

//  TC - O(N) SC - O(N)