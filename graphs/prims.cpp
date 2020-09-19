#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
    unordered_map<T, list<pair<T, int>>> m;
    list<pair<int, pair<T, T>>> edges;
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

    int prims(int src)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
        bool marked[100000];
        Q.push(make_pair(0,src));
        int ans = 0;
        while(!Q.empty()){
            pair<int,int>p = Q.top();
            Q.pop();
            src = p.second;
            int weight = p.first;
            // cycle
            if(marked[src]==true) continue;
            ans+=weight;
            marked[src] = true;
            for(auto i : m[src]){
                if(marked[i.first]==false) Q.push(make_pair(i.second,i.first));
            }
        }
        return ans;
    }
};

int main()
{
    graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 5);
    g.addEdge(1, 4, 4);
    cout<<g.prims(1);
}