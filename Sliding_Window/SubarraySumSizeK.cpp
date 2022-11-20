#include <bits/stdc++.h>
using namespace std;
int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i = 0;
        int j = 0;
        int sum = 0;
        int maxi = INT_MIN;
        while (j < N) {
            sum += Arr[j];
            if (j - i + 1 < K) {
                j++;
            }
           else  if (j - i + 1 == K) {
                maxi = max(maxi, sum);
                sum -= Arr[i];
                i++;
                j++;
            }
            
        }
        return maxi;
 }
 int main() {
 	int n;
 	cin>> n;
 	vector<int> a(n);
 	for (int i = 0;i < n; i++) {
 		cin >> a[i];
 	}
 	int k;
 	cin >> k;
 	cout << maximumSumSubarray(k, a, n);
 	return 0;
 }