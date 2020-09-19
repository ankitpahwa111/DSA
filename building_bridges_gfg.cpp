#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& arr) {
    // using binary search
    int ans = 0;
    vector<int>minVal(arr.size(),0);
    for(int val : arr){
        int lo = 0;
        int hi = ans;
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(minVal[mid]<=val) lo = mid+1;
            else hi = mid;
        }
        minVal[lo] = val;
        if(lo==ans) ans++;
    }
    return ans;
}

int Maxbridges(int X[],int Y[], int n){
    pair<int,int>bridges[n];
    for(int i=0;i<n;i++){
        bridges[i] = make_pair(X[i],Y[i]);
    }
    sort(bridges,bridges+n);
    vector<int>newY(n,0);
    for(int i=0;i<n;i++){
        newY[i] = bridges[i].second;
    }
    return lengthOfLIS(newY);
}

int main() {
	int n;
	cin>>n;
	int X[n],Y[n];
	for(int i=0;i<n;i++){
	    cin>>X[i];
	}
	for(int i=0;i<n;i++){
	    cin>>Y[i];
	}
	cout<<Maxbridges(X,Y,n);
}