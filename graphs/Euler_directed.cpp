#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
    map<T,list<T>> adjList;
    public:
    graph(){

    }
    void addEdge(T u , T v , bool bidirectional=true){
        adjList[u].push_back(v);
        if(bidirectional){
            adjList[v].push_back(u);
        }
    }
    void print(){
        for(auto i : adjList){
            cout<<i.first<<": ";
            for(auto j : i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }
    bool ifEulerPathExists(){
        unordered_map<T,int>indegree;
        unordered_map<T,int>outdegree;
        for(auto node : adjList){
            indegree[node.first] = 0;
        }
        for(auto node : adjList){
            for(auto neightbour : adjList[node.first])
                indegree[neightbour]++;
            outdegree[node] = adjList[node].size();
        }
        int count_in = 0;
        int count_out = 0;
        for(auto i : adjList){
            T node = i.first;
            if(indegree[node]==outdegree[node]+1)
                count_in++;
            if(outdegree[node]==indegree[node]+1)
                count_out++;
        }
        return (count_in==1 and count_out==1);
    }
    bool ifEulerCircuitExists(){
        unordered_map<T,int>indegree;
        unordered_map<T,int>outdegree;
        for(auto node : adjList){
            indegree[node.first] = 0;
        }
        for(auto node : adjList){
            for(auto neightbour : adjList[node.first])
                indegree[neightbour]++;
            outdegree[node] = adjList[node].size();
        }
        for(auto i : adjList){
            T node = i.first;
            if(indegree[node]!=outdegree[node])
                return false;
        }
        return true;
    }

};
int main() {
	int t;
	cin>>t;
	while(t--){
	    int V;
	    graph<int>g;
	    cin>>V;
	    vector<vector<int>>arr(V,vector<int>(V,0));
	    bool found = false;
	    string ans;
	    for(int i=0;i<V;i++){
	        bool is_island = true;
	        for(int j=0;j<V;j++){
	            cin>>arr[i][j];
	            if(arr[i][j]==1){
	                g.addEdge(i,j);
	                is_island = false;
	            }
	        }
	        if(is_island==true){
	            found = true;
	            ans = "False";
	        }
	    }
	   // g.print();
	   if(!found){
	       ans = g.ifEulerCircuitExists() ? "True" : "False";
	   }
	    if(V==1) ans = "True";
	    cout<<ans<<endl;
	}
	return 0;
}

