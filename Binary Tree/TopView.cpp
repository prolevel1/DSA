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
vector < int> topView(node* root) {
	queue<pair<node*, int> > q;
	map<int, int> mp;
	vector<int> ans;
	q.push({root, 0});
	while (!q.empty()) {
		node* temp = q.front().first;
		int line = q.front().second;
		q.pop();
		if (mp.find(line) == mp.end()) mp[line] = temp->val;
		if (temp->left != NULL) {
			q.push({temp->left, line - 1});
		}
		if (temp->right != NULL) {
			q.push({temp->right, line + 1});
		}
	}
	for (auto it : mp) {
		ans.push_back(it.second);
	}
	return ans;
}
int main() {
	struct node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);

	vector<int> ans;
	ans = topView(root);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}