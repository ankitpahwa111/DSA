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
    void bfs(T source){
        queue<T>q;
        map<T,bool>visited;
        q.push(source);
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" -> ";
            for( T neighbour : adjList[node]){
                if(visited[node]==false) q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }

};
int main(){
    graph<int> g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,4);
    g.addEdge(4,1);
    g.bfs(2);
}