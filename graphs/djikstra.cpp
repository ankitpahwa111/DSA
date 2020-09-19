#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
    unordered_map<T,list<pair<T,int>>> m;
    public:
    graph(){

    }
    void addEdge(T u , T v, int dist, bool bidir = true){
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
    }
    void print(){
        for(auto i : m){
            cout<<i.first<<"->";
            for(auto neighbour : m[i.first]){
                cout<<neighbour.first<<" "<<neighbour.second<<" , ";
            }
            cout<<endl;
        }
    }
    void dijkstra(T src){
        map<T,int> dist;
        for(auto i:m){
            dist[i.first] = INT_MAX;
        }
        set<pair<int,T>> s;
        dist[src]=0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto a = *(s.begin());
            s.erase(s.begin());
            T node = a.second;
            int d = a.first;
            for(auto neighbour : m[node]){
                if(dist[neighbour.first]>d + neighbour.second){
                    auto f = s.find(make_pair(dist[neighbour.first],neighbour.first));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[neighbour.first] = d + neighbour.second;
                    s.insert(make_pair(dist[neighbour.first],neighbour.first));
                }
            }
        }
        for(auto d : dist){
            cout<<d.first<<" - "<<d.second<<endl;
        }
    }
};

int main(){
    graph<int>g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.dijkstra(1);
}