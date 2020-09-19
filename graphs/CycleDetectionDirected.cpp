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
    bool DFSHelper(T node , map<T,bool> &visited, map<T,bool>&inStack){
        visited[node] = true;
        inStack[node] = true;
        for(auto neighbour : adjList[node]){
            if(inStack[neighbour]) return true;
            if(!visited[neighbour] and DFSHelper(neighbour,visited,inStack)) return true;
        }
        inStack[node] = false;
        return false;
    }
    bool isCyclicDFS(){
        map<T,bool>visited;
        map<T,bool> inStack;
        for(auto i : adjList){
            auto node = i.first;
            if(!visited[node]){
                if(DFSHelper(node,visited,inStack)) return true;
            }
        }
        return false;
    }
};
int main(){
    graph<int> g;
    g.addEdge(0,2,false);
    g.addEdge(0,1,false);
    g.addEdge(2,3,false);
    g.addEdge(2,4,false);
    g.addEdge(3,0,false);
    g.addEdge(4,5,false);
    g.addEdge(1,5,false);
    cout<<g.isCyclicDFS();
}