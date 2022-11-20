#include<bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &a) {
	int k, l, n = a.size();
	for (k = n - 2; k >= 0; k--) {
		if (a[k] < a[k + 1]) {
			break;
		}
	}
	if (k < 0) {
		reverse(a.begin(), a.end());
	}
	 else {
	 	for (l = n - 1; l < k; l--) {
	 		if (a[l] > a[k]) {
	 			break;
	 		}
	 	}
	 	swap (a[k], a[l]);
	 	reverse(a.begin() + k + 1, a.end());
	 }
}
int merge(int a[], int l, int mid, int r, int t[]) {
	int cnt = 0, i = l, j = mid, k = l;
	while (i <= mid - 1 && j <= r) {
		if (a[i] <= a[j]) {
			t[k++] = a[i++];
		}
		else {
			t[k++] = a[j++];
			cnt = cnt + (mid - i);
		}
	}
	while (i <= mid - 1) 
		t[k++] = a[i++];
	while (j <= r) 
		t[k++] = a[j++];
	for (i = l; i <= r; i++)
		a[i] = t[i];
	return cnt;

}
int searchElemenrRotated(vector<int> &a, int target) {
	int l = 0, h = a.size() - 1, mid;
	while (l <= h) {
		mid = (l + h) / 2;
		if (a[mid] == target) return mid;
		if (a[l] <= a[mid]) {
			if (target >= a[l] && target <= a[mid]) {
				h = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		else {
			if (a[mid] <= target && target <= a[h]) {
				l = mid + 1;
			}
			else {
				h = mid - 1;
			}
		}
	}
	return -1;
}
// int mergeSort(int l, int r, int a[], int t[]) {
// 	int cnt = 0, mid;
// 	if (r > l) {
// 		mid = (l + r) / 2;
// 		inv += mergeSort(l, mid, a, t);
// 		inv += mergeSort(mid + 1, h, a, t);
// 		inv += merge(a, l, mid + 1, r, t)
// 	}
// 	return inv;
// }
void resu(vector<int> &a, vector<int> &res) {
	int pos = 0;
	int neg = 1;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			res[pos] = a[i];
			pos+= 2;
		}
		else {
			res[neg] = a[i];
			neg += 2;
		}
	}
}
// void setZeroes(vector<vector<int>> a) {
// 	int col = 1;
// 	int n = a.size(), m = a[0].size();
// 	for (int i = 0; i < n; i++) {
// 		if (a[i][0] == 0) {
// 			for (int j = 1; j < m; j++) {
// 				if (a[i][j] == 0) {
// 					a[i][0] = 0;
// 					m[0][j] = 0;
// 				}
// 			}
// 		}
// 	}
// 	for (int i = n - 1; i >= 0; i--) {
// 		for (int j = m - 1; j >= 1; j--) {
// 			if (a[i][0] == 0 || a[0][j] == 0) {
// 				a[i][j] = 0;
// 			}
// 		}
// 		if (col == 0) {
// 			a[i][0] = 0;
// 		}
// 	}
// }

void rearrange(vector<int> &a) {
	int n = a.size();
	vector<int> res(n, 0);
	resu(a, res);
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}
int main() {
	int n; 
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int t;
	cin >> t;
	cout << searchElemenrRotated(arr,t);
	//rearrange(arr);
	return 0;
}