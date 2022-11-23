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
vector < int > bottomView(node* root) {
	vector <int> ans;
	queue<pair<node*, int>> q;
	q.push({root, 0});
	map<int, int> mp;
	while (!q.empty()) {
		node* temp = q.front().first;
		int line = q.front().second;
		q.pop();
		mp[line] = temp->val;
		if (temp->left != NULL) {
			q.push({temp->left, line - 1});
		}
		if (temp->right != NULL) {
			qq.push({temp->right, line + 1});
		}
	}
	for (auto it : mp) {
		ans.push_back(it.second);
	}
	return ans;
}

// TC - O(N) SC- O(N)