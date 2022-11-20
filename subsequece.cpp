#include<bits/stdc++.h>
using namespace std;
bool subsetSum(int i, vector<int> &a, int tot, vector<vector<int> > &dp) {
	if (tot == 0) return true;
	if (i == 0) return a[0] == tot;
	if (dp[i][tot] != -1) return dp[i][tot];
	bool notpick = subsetSum(i - 1, a, tot, dp);
	bool pick = false;
	if (a[i] <= tot) {
		pick = subsetSum(i - 1, a, tot - a[i], dp);
	}
	return dp[i][tot] =  pick || notpick;
}
int countSubset(int i, vector<int> &a, int tot, vector<vector<int> > &dp) {
	if (tot == 0) return 1;
	if (i == 0 ) return a[i] == tot;
	if (dp[i][tot] != -1) return dp[i][tot];
	int notpick = subsetSum(i - 1, a, tot, dp);
	int pick = 0;
	if (a[i] <= tot) {
		pick = subsetSum(i - 1, a, tot - a[i], dp);
	}
	return dp[i][tot] =  pick + notpick;
}
int knapsack(int i, int W, vector<int> &wt, vector<int> &val) {
	if (i == 0) {
		if (wt[i] <= W) 
			return val[i];
		return 0;
	}
	int notpick = knapsack(i - 1, W, wt, val);
	int pick = 0;
	if (wt[i] <= W) {
		pick = val[i] + knapsack(i - 1, W - wt[i], wt, val);
	}
	return max(pick, notpick);
}
int coinChange(int ind, vector<vector<int> > &dp, vector<int>& a, int amount) {
	if (ind == 0) {
		if (amount % a[0] == 0)
			return amount/a[0];
		return 1e9;
	}
	if (dp[ind][amount] != -1) return dp[ind][amount];
	int pick = 1e9;
	int ntpick = coinChange(ind - 1, dp, a, amount);
	if (a[ind] <= amount) {
		pick = coinChange(ind, dp, a, amount - a[ind]);
	}
	return dp[ind][amount] = min(pick, ntpick);
}
int findTargetSumWays(vector<int> &a, int target) {
	int n = a.size();
	int tot = 0;
	for (int i = 0; i < n; i++) {
		tot += a[i];
	}
	if ((tot - target) % 2 == 1) return 1;
	int newTraget = (tot - target) / 2;
	vector<vector<int> >dp(n + 1, vector<int>(newTraget, -1));
	return countSubset(n - 1, a, newTraget, dp);
}
int coinChange2(int ind, vector<int> &a, int tot, vector<vector<int> > &dp) {
	if (ind == 0) {
		if (tot % a[0] == 0)
			return 1;
		return 0;
	}
	if (ind < 0) return 0;
	if (dp[ind][tot] != -1) return dp[ind][tot];
	int np = coinChange2(ind - 1, a, tot, dp);
	int pick = 0;
	if (a[ind] <= tot) {
		pick = coinChange2(ind, a, tot - a[ind], dp);
	}
	return dp[ind][tot] = pick + np;
}
void solve(int n) {
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int t;
	cin >> 	t;
	
	//cout << knapsack(n - 1, W, a, val);
	//cout << findTargetSumWays(a, t);
	vector<vector<int> >dp(n + 1, vector<int>(t + 1, -1));
	cout << coinChange2(n - 1, a, t, dp);
	//cout << countSubset(n - 1, a, t, dp);
	//cout << subsetSum(n - 1, a, t, dp);
}
int main() {
	int n;
	cin >> n;
	solve(n);
	return 0;
}