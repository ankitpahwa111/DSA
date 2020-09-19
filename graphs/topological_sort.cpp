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
    void recursiveDFS(T node , map<T,bool> &visited, list<T>& ordering){
        visited[node] = true;
        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]){
                recursiveDFS(neighbour,visited,ordering);
            }
        }
        ordering.push_front(node);
    }
    void topological_dfs(){
        map<T,bool>visited;
        list<T> ordering;
        // for(auto node : adjList) visited[node.first]=false;
        for(auto i : adjList){
            if(!visited[i.first]) recursiveDFS(i.first,visited,ordering);
        }
        for(auto node : ordering) cout<<node<<" --> ";
    }
    void topological_bfs(){
        queue<T>q;
        map<T,bool> visited;
        map<T,int>indegree;
        for(auto node : adjList){
            visited[node.first] = false;
            indegree[node.first] = 0;
        }
        for(auto node : adjList){
            for(auto neightbour : adjList[node.first])
                indegree[neightbour]++;
        }
        for(auto node : adjList){
            if(indegree[node.first]==0) q.push(node.first);
        }
        while(!q.empty()){
            T lawda = q.front();
            cout<<lawda<<" --> ";
            q.pop();
            for(auto node : adjList[lawda]){
                indegree[node]--;
                if(indegree[node]==0) q.push(node);
            }
        }
    }

};
int main(){
    // graph<string> g;
    // g.addEdge("A","B",false);
    // g.addEdge("B","D",false);
    // g.addEdge("D","F",false);
    // g.addEdge("E","F",false);
    // g.addEdge("C","E",false);
    // g.addEdge("A","C",false);
    graph<int>g;
    g.addEdge(2,1,false);
    g.addEdge(3,2,false);
    g.addEdge(2,3,false);
    // g.addEdge(4,1,false);
    g.topological_dfs();
}