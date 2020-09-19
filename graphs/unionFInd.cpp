#include<bits/stdc++.h>
using namespace std;

class UnionFind {
	friend class Solution;
private:
	vector<int> parent;
	vector<int> rank;
public:

	UnionFind(int n) {
		parent.resize(n+1);
		rank.resize(n+1,0);
		init(n);
	}

	void init(int n) {
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
            rank[i] = 1;
		}
		return;
	}

	int find(int x) {
		if (parent[x] == x)
			return x;
		return parent[x]=find(parent[x]);
	}
	bool join(vector<int>& edge) {
		int x = edge[0];
		int y = edge[1];
		if ((x = find(x)) == (y = find(y))) {
			return false;
		}

		if (rank[x] < rank[y])
			parent[x] = y;
		else {
			if (rank[x] > rank[y])
				parent[y] = x;
			else {
				parent[x] = y;
				rank[y]++;
			}
		}
		return true;

	}
};