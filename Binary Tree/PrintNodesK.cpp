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
void markParent(node* &root, map<node*, node*> &mp) {
	queue <node*> q;
	q.push(root);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		if (temp->left) {
			mp[temp->left] = temp;
			q.push(temp->left);
		}
		if (temp->right) {
			mp[temp->right] = temp;
			q.push(temp->right);
		}
	}
}
void distanceK(node* root, node* target, int k) {
	map<node*, node*> mp;
	markParent(root, mp);
	map<node*, bool> vis;
	queue<node*> q;
	q.push(target);
	vis[target] = true;
	int dist = 0;
	while (!q.empty()) {
		int n = q.size();
		if (dist++ == k)  break;
		for (int i = 0; i < n; i++) {
			node* t = q.front();
			q.pop();
			if (!vis[mp[t]] && mp[t]) {
				q.push(mp[t]);
				vis[mp[t]] = true;
			}
			if (t->left && !vis[t->left]) {
				q.push(t->left);
				vis[t->left] = true;

			}
			if (t->right && !vis[t->right]) {
				q.push(t->right);
				vis[t->right] = true;
			}
		}
	}
	vector < int > ans;
	while (!q.empty()) {
		node* x = q.front();
		cout << x->val << " ";
		//ans.push_back(x->val);
		q.pop();
	}
	//return ans;

}
int main() {
	struct node * root = new node(20);
    root->left = new node(8);
    root->right = new node(22);
    root->left->left = new node(4);
    root->left->right = new node(12);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    node * target = root->left->right;
    vector < int> ans;
     distanceK(root, target, 2);
    //for (int i = 0; i < ans.size(); i++) {
   // 	cout << ans[i] << " ";
  //  }
    return 0;
}
