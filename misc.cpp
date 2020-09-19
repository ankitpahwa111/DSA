#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
    unordered_map<T, list<pair<T, int>>> m;
    list<pair<int, pair<T, T>>> edges;
    int parent[100000];
    map<pair<int, pair<T, T>>,bool>marked;

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
                marked[i] = true;
            }
        }
        return ans;
    }
    pair<int,int> lawda(int paisa){
        int o = kruskal();
        edges.sort();
        int ans = 0;
        int edge_selected=0;
        for(auto edge : edges){
            // cout<<edge.second.first<<" "<<edge.second.second<<endl;
            if(edge.first<=paisa and !marked[edge]){
                ans+=edge.first;
                edge_selected++;
                paisa-=edge.first;
            }
        }
        return make_pair(edge_selected,ans);
    }

};

int main()
{
    int vertices,edges,paisa;
    cin>>vertices>>edges>>paisa;
    graph<int>g;
    for(int i=0;i<edges;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g.addEdge(a,b,c);
    }
    pair<int,int>p = g.lawda(paisa);
    cout<<p.first<<" "<<p.second<<endl;
    // cout<<g.kruskal();
    return 0;
}