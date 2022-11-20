#include<bits/stdc++.h>
using namespace std;
vector < vector < int > > insert(vector < vector < int > >& intervals, vector < int > & newInterval) {
	vector < vector < int > > merge;
	int i = 0;
	int n = intervals.size();
	// skip (and add to output) all intervals that come before the 'newInterval'
	while (i < n && intervals[i][1] <= newInterval[0]) {
		merge.push_back(intervals[i++]);

	}
	//overlap condition
	while (i < n && intervals[i][0] <= newInterval[1]) {
		newInterval[0] = min(intervals[i][0], newInterval[0]);
		newInterval[1] = max(intervals[i][1], newInterval[1]);
		i++;
	}
	 // insert the newInterval
	merge.push_back(newInterval);
	while (i < n ) {
		merge.push_back(intervals[i]);
		i++;
	}
	// add all the remaining intervals to the output
	return merge;
}
int main() {
  vector < vector < int > > intervals;
intervals = {{1,3}, {6,9}};

vector < int > newInterval;
newInterval.push_back(2);
newInterval.push_back(5);
intervals = insert(intervals,newInterval);
for(int i=0;i<intervals.size();i++){
cout<<"["<<intervals[i][0]<<","<<intervals[i][1]<<"]"<<" ";
}
return 0;
}