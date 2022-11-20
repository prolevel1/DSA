#include<bits/stdc++.h>
using namespace std;
void solve(int i, string &s, string &f) {
	if (i == s.length()) {
		cout << f << " ";
		return;
	}
	f = f + s[i];
	solve(i + 1, s, f);
	f.pop_back();
	solve(i + 1, s, f);
}
//Combination Sum
void helper(int ind, vector<int> &a, int s, vector<int> &ds, vector<vector<int> > & ans) {
	int n = a.size();
	
		if (s == 0) {
			ans.push_back(ds);
			return;
		}
	
	for (int i = ind; i < a.size(); i++) {
		if (i > ind && a[i] == a[i-1]) continue;
		if (a[i] > s) break;
		ds.push_back(a[i]);
		helper(i + 1, a, s - a[i], ds, ans);
		ds.pop_back();
	}
}
vector<vector<int> >  combination(vector<int> &a, int s) {
	vector<int> ds;
	int n = a.size() - 1;
	vector<vector< int> >ans;
	sort(a.begin(), a.end());
	helper(0, a, s, ds, ans);
	return ans;
}
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s;
	cin >> s;
	vector < vector<int> > ans = combination(a, s);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
}
	return 0;

}