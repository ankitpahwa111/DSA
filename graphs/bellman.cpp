#include <bits/stdc++.h>
using namespace std;
#define INFINITY 1e9;
template <typename T>
class graph
{
    unordered_map<T, list<pair<T, int>>> m;
    vector<pair<int, pair<T, T>>> edges;
    int parent[100000];

public:
    graph()
    {
    }
    void addEdge(T u, T v, int dist, bool bidir = true)
    {
        m[u].push_back(make_pair(v, dist));
        edges.push_back(make_pair(dist, make_pair(u, v)));
        if (bidir)
        {
            m[v].push_back(make_pair(u, dist));
        }
    }
    void print()
    {
        for (auto i : m)
        {
            cout << i.first << "->";
            for (auto neighbour : m[i.first])
            {
                cout << neighbour.first << " " << neighbour.second << " , ";
            }
            cout << endl;
        }
    }

    void bellman(int source){
        map<T,int> distance;
        for(auto i : m){
            if(i.first==source) distance[i.first] = 0;
            else distance[i.first] = INFINITY;
        }
        // relaxations 
        for(int i=1;i<=m.size()-1;i++){
            for(auto j : edges){
                int src = j.second.first;
                int dest = j.second.second;
                int weight = j.first;
                if(distance[dest]>distance[src]+weight)
                    distance[dest] = distance[src] + weight;
            }
        }
        // also check for negative cycle by travelling once more and checking if distance got updated
        for(auto j : edges){
            int src = j.second.first;
            int dest = j.second.second;
            int weight = j.first;
            if(distance[dest]>distance[src]+weight){
                cout<<"negative cycle" ;
                return;
            }
        }
        for(auto i : distance){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
};

int main()
{
    graph<int> g;
    g.addEdge(2, 1, 1);
    g.addEdge(2, 3, 1);
    // g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 1);
    // g.addEdge(1, 4, 4);
    g.bellman(2);
}