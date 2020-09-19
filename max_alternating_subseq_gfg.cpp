#include <bits/stdc++.h>
using namespace std;

int maxAlternatingSumSub(int arr[], int n){
    vector<int>inc(n,0);
    vector<int>dec(n,0);
    bool flag = false;
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                if(flag){
                    inc[i] = max(inc[i],dec[j]+arr[i]);
                }
            }
            else if(arr[i]<arr[j]){
                flag = true;
                dec[i] = max(dec[i],inc[j]+arr[i]);
            }
            else if(arr[i]==arr[j]) continue;
        }
        if(!flag){
            inc[i] = arr[i];
            dec[i] = arr[i];
        }
        ans = max(ans,inc[i]);
        ans = max(ans,dec[i]);
    }
    return ans;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	cout<<maxAlternatingSumSub(arr,n);
}