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
bool isLeaf(node* root) {
	return !root->left && !root->right;
}
void addLeft(node* &root, vector < int > &ans) {
	node* temp = root->left;
	while (temp) {
		if (isLeaf(temp)) ans.push_back(temp->val);
		if (temp->left) addLeft(temp->left, ans);
		if (temp->right) addLeft(temp->right, ans);
	}
}
void addLeaf(node* root, vector < int > &ans) {
	if (!isLeaf(root)) {
		ans.push_back(root->val);
		return;
	}
	if (root->left) addLeaf(root->left, ans);
	if (root->right) addLeaf(root->right, ans);
}
void addRight(node* &root, vector < int > &ans) {
	vector <int > res;
	node* temp = root->right;
	while (temp) {
		if (isLeaf(temp)) res.push_back(temp->val);
		if (temp->right) addRight(temp->right, ans);
		if (temp->left) addRight(temp->left, ans);
		
	}
	for (int i = res.size(); i>= 0; i--) {
		ans.push_back(res[i]);
	}
}
void printBoundary(node* root) {
	vector < int > ans;
	if (!isLeaf(root)) ans.push_back(root->data);
	addLeft(root->left, ans);
	addLeaf(root, ans);
	addRight(root->right, ans);
	return ans;
}




