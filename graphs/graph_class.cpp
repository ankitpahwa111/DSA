// Adjacency List 
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
    map<T,list<T>> adjList;
    public:
    graph(int nodes){
        for(int i=0;i<nodes;i++){
            list<T> l;
            adjList[i]=l;
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

};
int main(){
    graph<int> g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    // g.addEdge(2,3);
    g.print();
}