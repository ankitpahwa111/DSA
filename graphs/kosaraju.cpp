// Adjacency List
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
public:
    map<T, vector<T>> adjList;
    list<pair<T, T>> edges;
    graph()
    {
    }
    void addEdge(T u, T v, bool bidirectional = true)
    {
        adjList[u].push_back(v);
        edges.push_back(make_pair(u, v));
        if (bidirectional)
        {
            adjList[v].push_back(u);
        }
    }
    void print()
    {
        for (auto i : adjList)
        {
            cout << i.first << ": ";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
    void recursiveDFS(T node, map<T, bool> &visited)
    {
        visited[node] = true;
        for (auto neighbour : adjList[node])
        {
            if (!visited[neighbour])
                recursiveDFS(neighbour, visited);
        }
        return;
    }
    void dfs(T source)
    {
        map<T, bool> visited;
        for (auto node : adjList)
            visited[node.first] = false;
        recursiveDFS(source, visited);
        return;
    }
    void fillTheStack(T node, stack<T> &s, map<T, bool> &visited)
    {
        visited[node] = true;
        for (auto i : adjList[node])
        {
            if (!visited[i])
                fillTheStack(i, s, visited);
        }
        s.push(node);
    }
    void transpose()
    {
        for (auto i : adjList)
        {
            adjList[i.first].clear();
        }
        for (auto i : edges)
        {
            adjList[i.second].push_back(i.first);
        }
    }
    int kosaraju()
    {
        stack<T> s;
        map<T, bool> visited;
        for (auto i : adjList)
        {
            if (!visited[i.first])
            {
                fillTheStack(i.first, s, visited);
            }
        }
        transpose();
        int ans = 0;
        map<T, bool> visited_again;
        while (!s.empty())
        {
            T lawda = s.top();
            // cout<<lawda<<" ";
            s.pop();
            if (!visited_again[lawda])
            {
                recursiveDFS(lawda, visited_again);
                ans++;
            }
        }
        return ans;
    }
};
int main()
{
    graph<int> g;
    g.addEdge(1, 0, false);
    g.addEdge(2, 1, false);
    g.addEdge(0, 2, false);
    g.addEdge(0, 3, false);
    g.addEdge(3, 4, false);
    cout << g.kosaraju();
}