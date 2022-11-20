#include<bits/stdc++.h>
using namespace std;
bool jumpGame1(vector<int> &a, int n) {
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		if (maxi < i) return false;
		maxi = max(maxi, i + a[i]);
	}
	return true;
}

//Jump Game 2

int jump(vector<int>& nums) {
        int curr = 0;
        int ans = 0 ; // jump
        int maxi = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            maxi = max(maxi, i + nums[i]);
            if (i == curr) {
                ans++;
                curr = maxi;
            }
        }
        return ans;
    }
    int main() {
    	int n; cin >> n; 
    	vector<int> a(n);
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	cout << jumpGame1(a, n);
    	cout << jump(a);
    	return 0;
    }