#include<bits/stdc++.h>
using namespace std;
class Pair{
	public:
	int val;
	int row;
	int col;

	Pair(int v, int r, int c) {
		val = v;
		row = r;
		col = c;
	}
};
struct myCompare
{
	bool operator(Pair &p1, Pair &p2) {
		return p1.val > p2.val;
	}
};
vector<int> mergeKSorted(vector<vector<int> > &arr, int k, vector<int> &ans) {
	priority_queue<Pair, vector<Pair>, myCompare> pq;
	for (int i = 0; i < k; i++) {
		Pair p(arr[i][0], i, 0);
		pq.push(p);
	}
	while (!pq.empty()) {
		Pair p = pq.top();
		pq.pop();
		ans.push_back(p.val);
		int r = p.row, c = p.col;
		if (c + 1 < arr[r].size()) {
			Pair d(arr[r][c + 1], r, c + 1);
			pq.push(d);
		}
	}
	return ans;

}
int main() {

	vector<vector<int> > arr { { 2, 6, 12 },
                            { 1, 9 },
                            { 23, 34, 90, 2000 } };
    int k = 3;
    vector<int> ans;
    ans = mergeKSorted(arr, k, ans);
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
    return 0;


}
