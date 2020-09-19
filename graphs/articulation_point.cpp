#include<bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
    unordered_map<T,list<T>> adjList;
    public:
    graph(int V){
        for(int i=1;i<=V;i++){
            list<int>l;
            adjList[i] = l;
        }
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
    int children;
    int main_source;
    int t;
    int parent[30001], disc[30001], low[30001], ap[30001];
    bool visited[30001];
    void dfs(T u, T Parent){
        visited[u] = true;
        disc[u] = t;
        low[u] = t;
        parent[u] = Parent;
        t++;
        // if(low[u]==-1) low[u] = u;
        for(auto v : adjList[u]){
            if(v==Parent) continue;
            if(visited[v]==true){
                low[u] = min(low[u],disc[v]);
            }
            else{
                if(u==main_source) children++;
                dfs(v,u);
                low[u] = min(low[u],low[v]);
                if(u!=main_source and disc[u]<=low[v]) ap[u] = 1;
            }
        }
    }
    int Articulation_points(int V, T main_source){
        this->children = 0;
        this->t = 0;
        this->main_source = main_source;
        // int parent[30001],disc[30001],low[30001];
        // bool visited[30001];
        // for(int i=1;i<=V;i++){
        //     T node = i;
        //     parent[node] = -1;
        //     disc[node] = -1;
        //     low[node] = -1;
        //     visited[node] = false;
        // }
        // low[main_source] = 0;
        memset(disc,0,sizeof(disc));
        memset(low,0,sizeof(low));
        memset(visited,0,sizeof(visited));
        memset(parent,-1,sizeof(parent));
        memset(ap,0,sizeof(ap));
        dfs(1,-1);
        if(children>=2) ap[1] = 1;
        int ans = 0;
        for(int i=1;i<=V;i++){
	        if(ap[i]==1){
	           // cout<<i<<endl;
	            ans++;
	        }
	    }
	    return ans;
    }

};
int main() {
	int t;
	cin>>t;
	while(t--){
	    int V,E;
	    cin>>V>>E;
	    graph<int>g(V);
	    int main_source = 1;
	    for(int i=0;i<E;i++){
	        int u,v;
	        cin>>u>>v;
	        main_source = u;
	        g.addEdge(u,v);
	    }
	   //V = 6962;
	   //for(int i=1;i<=3578;i++){
	   //    g.addEdge(i,i+1);
	   //}
	    int ans = g.Articulation_points(V,1);
	    cout<<ans<<endl;
	}
	return 0;
}




