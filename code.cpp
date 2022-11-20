//0 -> 01
//1 -> 10



//L0 : 0
//L1 = T(L0) = T(0) = 01
//L2 = T(L1) = T(01) = 0110
//L3 = T(L2) = T(0110) = 01101001
//L4 = T(L3) = 0110100110010110
//l5= 01101001100101101001011001101001

#include<bits/stdc++.h>
using namespace std;


int firstOcc(int arr[], int t, int n) {
	int res = -1;
	int l = 0, h = n -1 ;
	int mid;
	while (l <= h) {
		mid = (l + h) / 2;
		if (arr[mid] == t) {
			res = mid;
			h = mid - 1;
		}
		else if (arr[mid] < t) {
			l = mid + 1;
		}
		else {
			h = mid - 1;
		}
	}
	return res;
}
int lastOcc(int arr[], int t, int n) {
	int l = 0;
	int h = n - 1;
	int mid;
	int res = -1;
	while (l <= h) {
		mid = (l + h) / 2;
		if (arr[mid] == t) {
			res = mid;
			l = mid + 1;
		}
		else if (arr[mid] > t) {
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return res;
}
int peakElement(int arr[], int n) {
	int l = 0;
	int h = n - 1;
	int mid;
	//int res = -1;
	while (l <= h) {
		mid = (l + h) / 2;
		if (mid == 0) 
			return arr[0] > arr[1] ? arr[0] : arr[1];
		if (mid == n - 1) 
			return arr[n-1] > arr[n-2] ? arr[n-1] : arr[n-2];
		if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1]) {
			return arr[mid];
		}
		if (arr[mid] < arr[mid - 1]) {
			h = mid - 1;
		}
		else  {
			l = mid + 1;
		}
	}
	return arr[l];
}
bool search2(vector<int> &arr, int t, int n) {
	int l = 0;
	int h = n - 1;
	int mid;
	while (l <= h) {
		mid = (l + h) / 2;
		if (arr[mid] == t) return true;
		if ((arr[l] ==arr[mid]) && (arr[h] == arr[mid])) {
			l++;
			h--;

		}
		else if (arr[l] <= arr[mid]) {
			if (arr[l] <= t && arr[mid] > t) {
				h = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		else {
			if (arr[mid] <t && t <= arr[h]) {
				l = mid + 1;
			}
			else {
				h = mid - 1;
			}
		}
	}
	return false;
}
int minimumRotattedSorted(vector<int> &a, int n) {
	int l = 0;
	int h = n - 1;
	int mid;
	while(l < h) {
		mid = (l + h) / 2;
		if (a[l] < a[h]) return a[l];
		if (a[mid] > a[h]) {
			l =  mid + 1;
		}
		else {
			h = mid;
		}
		cout << "mid" << " " << l;
	}
	return a[l];
}
int main() {
	int n ;
	cin >> n;
	//5,7,7,8,8,10
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x;
	cin >> x;
	//cout << firstOcc(arr, x, n);
	//cout << lastOcc(arr, x, n);
	//cout << bs(arr, x, n);
	//cout << peakElement(arr, n);
	//if (search2(arr, x, n) == true) cout << "found";
	//else 
	//	cout << "no";
	cout << minimumRotattedSorted(arr, n);
	return 0;
}