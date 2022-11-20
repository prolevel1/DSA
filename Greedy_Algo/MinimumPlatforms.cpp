#include<bits/stdc++.h>
using namespace std;
int minimumPlatforms(int arr[], int dep[], int n) {
		sort(arr, arr + n);
    	sort(dep, dep + n);
    	int i = 1; 
    	int j = 0;
    	int platform = 1;
    	int maxi = 1;
    	while (i < n && j < n) {
    	    if (arr[i] <= dep[j]) {
    	        platform++;
    	        i++;
    	    }
    	    else {
    	        platform--;
    	        j++;
    	    }
    	    maxi = max(maxi, platform);
    	}
    	return maxi;
}
int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<minimumPlatforms(arr,dep, n)<<endl;
    return 0; 
 }