#include <bits/stdc++.h>
using namespace std;

int lengthOfdecLIS(int arr[], int n) {
    // using binary search
    int ans = 0;
    vector<int>minVal(n,0);
    for(int i=0;i<n;i++){
        int val = arr[i];
        int lo = 0;
        int hi = ans;
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(minVal[mid]<val) hi = mid;
            else lo = mid+1;
        }
        minVal[hi] = val;
        if(hi==ans) ans++;
    }
    return ans;
}

int minNumberOfIncSubs(int arr[], int n){
    return lengthOfdecLIS(arr,n);
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	cout<<minNumberOfIncSubs(arr,n);
}