#include<bits/stdc++.h>
using namespace std;
struct Sequence {
	int jobId;
	int deadline;
	int profit;

};
class Solve {
	public:
		bool static compar(Sequence a, Sequence b) {
			return (a.profit > b.profit);
		}
		pair<int, int> scheduling(Sequence arr[], int n) {
			sort(arr, arr + n, compar);
			int maxi = arr[0].deadline;
			for (int i = 0; i < n; i++) {
				maxi = max(maxi, arr[i].deadline);
			}
			int slot[maxi + 1];
			for (int i = 0; i <= maxi; i++) {
				slot[i] = -1;
			}
			int cntJobs = 0, totProfit = 0;
			for (int i = 0;i  < n; i++) {
				for (int j = arr[i].deadline; j > 0; j--) {
						if (slot[j] == -1) {
							slot[j] = i;
							cntJobs++;
							totProfit += arr[i].profit;
							break;
						}
				}
			}
			return make_pair(cntJobs, totProfit);
		}

};
int main() {
	int n = 4;
	Sequence arr[4] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};
	Solve ob;
	  pair < int, int > ans = ob.scheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;
   return 0;
}