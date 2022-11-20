#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node* left;
	struct Node* right;

};
Node* insertNode(int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void printTree(Node* root) {
	if (root ==NULL) return;
	printTree(root->left);
	cout << root->data << " ";
	printTree(root->right);
}
bool isValid(Node* root, int minval, int maxval) {
	if (root == NULL) return true;
	if (root->data >= maxval || root->data <= minval) return false;
	return isValid(root->left, minval, root->data) && isValid(root->right, root->data, maxval);
}
void solveBst(Node* root) {
	bool x = isValid(root, INT_MIN, INT_MAX);
	if (x) {
		cout << "valid";

	}
	else {
		cout << "not";
	}
}
//LCA BST
Node* lca(Node* root, Node* p, Node* q) {
	if (root == NULL) return NULL;
	if (p->data < root->data && q->data < root->data)
		return lca(root->left, p, q);
	if (p->data > root->data && q->data > root->data)
		return lca(root->right, p, q);
	return root;
}
void lcaPrint(Node* root, Node* p, Node* q) {
	Node* temp = lca(root, p, q);
	cout << temp->data << " ";
}
int main() {
	struct Node* root = insertNode(6);
	root->left = insertNode(2);
	root->right= insertNode(8);
	root->left->left = insertNode(0);
	root->left->right = insertNode(4);
	root->right->left = insertNode(7);
	root->right->right = insertNode(9);
	struct Node* p = insertNode(4);
	struct Node* q = insertNode(0);
	//root->left->right = insertNode(5);
	//solveBst(root);
	lcaPrint(root, p, q);
	
}