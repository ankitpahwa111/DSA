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
    void initialize()
    {
        for (int i = 0; i < m.size(); i++)
            parent[i] = i;
    }
    int root(int x)
    {
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void union1(int x, int y)
    {
        int p = root(x);
        int q = root(y);
        parent[p] = parent[q];
    }
    int kruskal()
    {
        initialize();
        edges.sort();
        edges.reverse();
        int ans = 0;
        for (auto i : edges)
        {
            int x = i.second.first;
            int y = i.second.second;
            int weight = i.first;
            if (root(x) != root(y))
            {
                ans += weight;
                union1(x, y);
                cout<<i.first<<" ";
            }
        }
        return ans;
    }
};

int main()
{
    graph<int> g;
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 3);
    // g.addEdge(3, 4, 5);
    g.addEdge(1, 4, 1);
    g.addEdge(4,5,5);
    g.addEdge(5,6,4);
    g.addEdge(4,6,5);
    cout<<g.kruskal();
}