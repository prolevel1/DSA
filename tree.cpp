#include <bits/stdc++.h>
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
void levelOrder(Node* root) {
	vector<int> ans;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int n = q.size();
		for (int i = 0; i < n; i++) {
			Node* temp = q.front();
			q.pop();
			ans.push_back(temp->data);
			if (temp->left != NULL) {
				q.push(temp->left);
			}
			if (temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
void preOrder(Node* root) {
	vector<int> ans;
	stack<Node*> st;
	st.push(root);
	while (!st.empty()) {
		Node* t = st.top();
		ans.push_back(t->data);
		st.pop();
		if (t-> right != NULL) {
			st.push(t->right);
		}
		if (t->left != NULL) {
			st.push(t->left);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "";
	}
	cout << endl;
}
void inorder(Node* root) {
	vector<int> ans;
	stack<Node*> st;
	Node* curr = root;
	while (true) {
		if (curr != NULL) {
			st.push(curr);
			curr = curr->left;
		}
		else {
			if (st.empty()) break;
			curr = st.top();
			
			ans.push_back(curr->data);
			st.pop();
			curr = curr->right;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "";
	}
	cout << endl;

}
//height of binary tree
int maxDEpth(Node* root) {
	if (root == NULL) return 0;
	int l = maxDEpth(root->left);
	int r = maxDEpth(root->right);
	return 1 + max(l, r);
}
//Balanced Binary tree

int dfs1(Node* root) {
	if (root == NULL) return 0;
	int l = dfs1(root->left);
	if (l == -1) return -1;
	int r = dfs1(root->right);
	if (r == -1) return -1;
	
	if (abs(l - r) > 1) return -1;
	return 1 + max(l, r);
}
void balancedTree(Node* root) {
	int x = dfs1(root);
	if (x == -1) {
		cout << "It is balanced";
	}
	else {
		cout << "not balanced";
	}
}
int dia(Node* root, int &diameter) {
	if (!root) return 0;
	int lh = dia(root->left, diameter);
	int rh = dia(root->right, diameter);
	diameter = max(diameter, (lh + rh));
	return 1 + max(lh, rh);
}
//Diameter binary tree
int diameterTree(Node* root) {
	int diameter = 0;
	dia(root, diameter);
	return diameter;
}


bool isLeaf(Node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(Node * root, vector < int > & res) {
  Node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(Node * root, vector < int > & res) {
  Node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(Node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}

//Boundary Traversal
void boundary(Node* root) {
	vector<int> ans;
	// 3cases
	if (!isLeaf(root)) ans.push_back(root->data);
	//all leaf nodes
	addLeftBoundary(root, ans);
	//add right boundary case
	addLeaves(root, ans);
	addRightBoundary(root, ans);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "";
	}
	cout << endl;
}
bool getPath(Node* root, vector<int> &a, int x) {
	if (root == NULL) return false;
	a.push_back(root->data);
	if (root->data == x) return true;
	if(getPath(root->left, a, x) || getPath(root->right, a, x))
		return true;
	return false;
}
void rootToLeaf(Node* root, int x) {
	vector<int> a;
	if(getPath(root, a, x)) {
		cout << "path";
	}
	else {
		cout << "no";
	}
}

//LowestCommon Ancestor
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
	if (root == p || root == NULL || root == q) return root;
	Node* lh = lowestCommonAncestor(root->left, p, q);
	Node* rh = lowestCommonAncestor(root->right, p, q);
	if (lh == NULL) {
		return rh;
	}
	else if(rh == NULL) {
		return lh;
	}
	else {
		return root;
	}
}
void lcs(Node* root, Node* p, Node* q) {
	Node* temp = lowestCommonAncestor(root, p, q);
	cout << temp->data;
}
//children Sum Property
void checkChildren(Node* root) {
	if (root == NULL) return;
	int child = 0;
	if (root->left != NULL) {
		child += root->left->val;
	}
	if (root->right != NULL) {
		child += root->right->data;
	}
	if (child < root->data) {
		if (root->left) root->left->data = root->data;
		else if (root->right) root->right->data = root->data;
	}
	checkChildren(root->left);
	checkChildren(root->right);
	int tot = 0;
	if (root->left) tot += root->left->data;
	if (root->right) tot += root->right->data;
	if (root->left || root->right) root->data = tot;
}
int main() {
	// struct Node* root = insertNode(1);
	// root->left = insertNode(2);
	// root->left->left = insertNode(4);
	// root->left->right = insertNode(5);
	//levelOrder(root);
	//inorder(root);
	//cout << maxDEpth(root);
	//balancedTree(root);
	struct Node* root = insertNode(1);
  root -> left = insertNode(2);
  root -> left -> left = insertNode(3);
  root -> left -> left -> right = insertNode(4);
  root -> left -> left -> right -> left = insertNode(5);
  root -> left -> left -> right -> right = insertNode(6);
  root -> right = insertNode(7);
  root -> right -> right = insertNode(8);
  root -> right -> right -> left = insertNode(9);
  root -> right -> right -> left -> left = insertNode(10);
  root -> right -> right -> left -> right = insertNode(11);
	//cout << diameterTree(root);
  //levelOrder(root);
  //boundary(root);
  //rootToLeaf(root, 15);
  //struct Node* p = insertNode(6);
  //struct Node* q = insertNode(7);
  //lcs(root, p, q);
  //checkChildren(root);
	return 0;
}