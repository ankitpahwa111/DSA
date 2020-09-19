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
        if(visited[node]==true){
            return ;
        }
        visited[node] = true;
        // cout<<node<<" -> ";
        for(auto neighbour : adjList[node]){
            recursiveDFS(neighbour,visited);
        }
    }
    int connected_components(T source){
        map<T,bool>visited;
        int component=1;
        for(auto node : adjList){
            visited[node.first] = false;
        }
        recursiveDFS(source,visited);
        for(auto node : adjList){
            if(!visited[node.first]){
                recursiveDFS(node.first,visited);
                component++;
            }
        }
        return component;
    }

};
int main(){
    graph<int> g;
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(0,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    cout<<g.connected_components(1);
}