// Adjacency List 
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
    void recursiveDFS(T node , map<T,bool> &visited){
        visited[node] = true;
        cout<<node<<" -> ";
        for(auto neighbour : adjList[node]){
            if(!visited[neighbour])
                recursiveDFS(neighbour,visited);
        }
        return;
    }
    void dfs(T source){
        map<T,bool>visited;
        for(auto node : adjList) visited[node.first]=false;
        recursiveDFS(source,visited);
        return ;
    }

};
int main(){
    graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,3);
    g.dfs(2);
}