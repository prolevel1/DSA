#include<bits/stdc++.h>
using namespace std;
void subset(int i, int s, vector<int> &a, vector<int> &ans) {
	if (i == a.size()) {
		ans.push_back(s);
		return;
	}
	subset(i + 1, s + a[i], a, ans);
	subset(i + 1, s, a, ans);
}
void subsetII(int ind, vector<int> &a, vector<int> &ds, 
	vector<vector<int> > &ans) {
	ans.push_back(ds);
	for (int i = ind; i < a.size(); i++) {
		if (i != ind && a[i] == a[i - 1]) continue;
		ds.push_back(a[i]);
		subsetII(ind + 1, a, ds, ans);
		ds.pop_back();
	}
}
void solve(int n, vector<int> &a) {
	vector<int> ds;
	vector<vector<int> > ans;
	subsetII(0, a, ds, ans);
	cout<<"The unique subsets are "<<endl;
   cout << "[ ";
   for (int i = 0; i < ans.size(); i++) {
      cout << "[ ";
      for (int j = 0; j < ans[i].size(); j++)
         cout << ans[i][j] << " ";
      cout << "]";
   }
   cout << " ]";
	// subset(0, 0, a,  ans);
	// for (int i = 0; i < ans.size(); i++) {
	// 	cout << ans[i] << " ";
	// }
	// cout << endl;
}
void f1(int open, int close, vector<string> &ans, string s) {
	if (open == 0 && close == 0) {
		ans.push_back(s);
		return;
	}
	if (open > 0) f1(open - 1, close, ans, s + '(');
	if (open < close) f1(open, close - 1, ans , s + ')');
}
void generateParenthesis(int n) {
	vector<string> ans;
	f1(n, n, ans, "");
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n; 
	// vector<int> a(n);
	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i];
	// }
	//solve(n, a);
	generateParenthesis(n);
	return 0;
}