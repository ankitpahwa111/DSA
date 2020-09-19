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
    bool isCyclicBFS(T source){
        queue<T>q;
        map<T,bool>visited;
        map<T,T> parent;
        parent[source] = source;
        q.push(source);
        while(!q.empty()){
            T node = q.front();
            q.pop();
            visited[node] = true;
            for(auto neighbour : adjList[node]){
                if(visited[neighbour] and parent[node]!=neighbour) return true;
                else if(!visited[neighbour]){
                    q.push(neighbour);
                    parent[neighbour] = node;
                    visited[neighbour]=true;
                }
            }
        }
        return false;
    }
    bool DFSHelper(T node , map<T,bool> &visited, T parent){
        visited[node]=true;
        for(auto neighbour : adjList[node]){
            if(visited[neighbour] and neighbour!=parent) return true;
            else if(!visited[neighbour] and DFSHelper(neighbour,visited,node)) return true;
        }
        return false;
    }
    bool isCyclicDFS(T node){
        map<T,bool>visited;
        for(auto i : adjList){
            auto node = i.first;
            if(!visited[node]){
                if(DFSHelper(node,visited,node)) return true;
            }
        }
        return false;
    }

};
int main(){
    graph<string> g;
    g.addEdge("A","B");
    g.addEdge("B","D");
    g.addEdge("D","F");
    g.addEdge("E","F");
    g.addEdge("C","E");
    g.addEdge("A","C");
    cout<<g.isCyclicDFS("A");
}