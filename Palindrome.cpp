#include<bits/stdc++.h>
using namespace std;
void f(int ind, )
void palindromePartition(string &s) {
	vector<string> ds;
	vector<vector<string>> ans;
	f(0, s, ds, ans);
	for (auto i: ans) {
    cout << "[ ";
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] ";
  }
  cout << "]";

}
int main() {
	string s;
	cin >> s;
	palindromePartition(s);
}