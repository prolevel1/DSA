#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> ans;
	sort(intervals.begin(), intervals.end());
	 vector<int> temp = intervals[0];
        for (auto it : intervals) {
            if (it[0] <= temp[1]) {
                temp[1] = max(temp[1], it[1]);
            }
            else {
                ans.push_back(temp);
                temp = it;
            }
            
        }
        ans.push_back(temp);
        return ans;
    }
}


//NON OVERLAPPING INTERVALS
bool static comp(vector<int> &a,vector<int> &b) {
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = -1;
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> temp = intervals[0];
        for (auto i : intervals) {
            if (i[0] < temp[1]) {
                ans++;
            }
            else {
                temp = i;
            }
        }
        return ans;
    }
};
