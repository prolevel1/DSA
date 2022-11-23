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
vector < vector < int > > zigzag(node* root) {
	vector < vector < int > > ans;
	queue<node*> q;
	bool flag = true;
	q.push(root);
	while (!q.empty()) {
		int n = q.size();
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			node* temp = q.front();
			q.pop();
			int ind = (flag) ? i : n - i - 1;
			res[ind] = temp->val;
			if (temp->left != NULL) {
				q.push(temp->left);
			}
			if (temp->right != NULL) {
				q.push(temp->right);
			}
		}
		flag = !flag;
		ans.push_back(res);
	}
	return ans;
}
int main() {
	struct node *root = new node(3);
	root->left = new node(9);
	root->right = new node(20);
	root->left->left = new node(15);
	root->left->right = new node(7);
	vector < vector < int > > ans;
	ans = zigzag(root);
	for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}


//  TC - O(N)  SC - O(N)