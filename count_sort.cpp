#include <bits/stdc++.h>
using namespace std;

void CountSort(int *arr, int n, vector<int>&ans){
    int maxi = *max_element(arr,arr+n);
    vector<int>freq(maxi+1,0);
    // cout<<n<<endl;
    for(int i=0;i<n;i++){
        // if(freq[arr[i]]==-1) freq[arr[i]]=1;
        // else 
        // cout<<arr[i]<<" ";
        freq[arr[i]]++;
    }
    for(int i=1;i<freq.size();i++){
        freq[i] += freq[i-1];
        // cout<<freq[i]<<" ";
    }
    // cout<<endl;
    for(int i=0;i<n;i++){
        // if(freq[arr[i]]==0) continue;
        if((ans[freq[arr[i]]-1])!=-1) continue;
        ans[freq[arr[i]]-1] = arr[i];
        freq[arr[i]]--;
    }
    return ;
}
void helper(int n, vector<int>&ans){
    int arr[100000];
    int i=0;
    while(n){
        arr[i] = (n%10);
        n/=10;
        i++;
    }
    CountSort(arr,i,ans);
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int loda = stoi(s);
	    vector<int>ans(s.length(),-1);
	    helper(loda,ans);
	    for(int i : ans) cout<<i;
	    cout<<endl;
	}
	return 0;
}