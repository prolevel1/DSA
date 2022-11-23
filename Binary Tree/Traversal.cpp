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
// root , left , right
void preorder(node* root) {
	if (root == NULL) return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}
//Left Root Right
void inorder(node* root) {
	if (root == NULL) return;
	
	preorder(root->left);
	preorder(root->right);
	cout << root->val << " ";
}
// Left Right Root
void postorder(node* root) {
	if (root == NULL) return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}
int main() {
	struct node *root = new node(1);
	root->left = new node(12);
  root->right = new node(9);
  root->left->left = new node(5);
  root->left->right = new node(6);

cout << "preorder traversal aree" << " " << "\n";
preorder(root);
cout << "\nInorder Traversal "<< " ";
inorder(root);

cout << "\nPostOrder Traversal "<< " ";
postorder(root);
return 0;
}