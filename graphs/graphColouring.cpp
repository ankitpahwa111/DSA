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
    bool isSafe(T k , int c, map<T,int>&colour){
        for(auto i : adjList[k]){
            if(colour[i]==c) return false;
        }
        return true;
    }
    bool ColourBacktracking(T k, int n , map<T,int>&colour, map<T,bool>&visited){
        if(adjList.count(k)==0) return false;
        for(int i=1;i<=n;i++){
            if(isSafe(k,i,colour)){
                colour[k]=i;
                ColourBacktracking(k+1,n,colour,visited);
            }
        }
    }
    map<T,int> Colourme(int n, T source){
        map<T,int>colour;
        for(auto i : adjList){
            colour[i.first] = -1;
        }
        map<T,bool>visited;
        ColourBacktracking(source,n,colour,visited);
        return colour;
    }
};
int main(){
    graph<int> g;
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(3,2);
    // g.addEdge(0,2);
    map<int,int> colour = g.Colourme(2,0);
    map<int,int>::iterator i =colour.begin();
    while (i!=colour.end())
    {
        cout<<i->first<<" "<<i->second<<endl;
        i++;
    }
    
}