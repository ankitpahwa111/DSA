#include<bits/stdc++.h>
using namespace std;

pair<int,int> MaxMin(string &symb, string &oper){
    vector<vector<int>>maxi(symb.size(),vector<int>(symb.size(),INT_MIN));
        vector<vector<int>>mini(symb.size(),vector<int>(symb.size(),INT_MAX));
        for(int i=0;i<symb.size();i++){
            int num = stoi(symb.substr(i,1));
            mini[i][i] = num;
            maxi[i][i] = num;
        }
        for(int gap=1;gap<symb.size();gap++){
            for(int left = 0, right=gap; right<symb.size();left++,right++){
                for(int cut = left; cut<right; cut++){
                    char op = oper[cut];
                    // cout<<left<<" "<<right<<" "<<op<<endl;
                    if(op=='+'){
                        maxi[left][right] = max(maxi[left][cut]+maxi[cut+1][right],maxi[left][right]);
                        mini[left][right] = min(mini[left][cut]+mini[cut+1][right],mini[left][right]);
                    }
                    else{
                        maxi[left][right] = max(maxi[left][cut]*maxi[cut+1][right],maxi[left][right]);
                        mini[left][right] = min(mini[left][cut]*mini[cut+1][right],mini[left][right]);
                    }
                }
            }
        }
        return {maxi[0][symb.size()-1],mini[0][symb.size()-1]};
}

int main(){
    string nums;
    cin>>nums;
    string ops;
    cin>>ops;
    pair<int,int>p = MaxMin(nums,ops);
    cout<<p.first<<" "<<p.second;
}