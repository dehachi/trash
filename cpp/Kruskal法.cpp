/*
Kruskal法

最小全域木の辺の重みの総和: kruskal(頂点数, 辺リスト)
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct UnionFind {
	int flen;
	vector<int> par;
	UnionFind(int n) {build(n);}
	void build(int n) {
		par.assign(n, -1);
		flen = n;
	}
	int root(int x) {
		if (par[x] < 0) return x;
		return par[x] = root(par[x]);
	}
	bool merge(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		flen--;
		return true;
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	int size(int x) {
		return -par[root(x)];
	}
	int forest_size() {
		return flen;
	}
};

struct Edge {
	int u, v;
	ll cost;
};

int kruskal(int n, vector<Edge>& edges) {
	int m = edges.size();
	auto f = [](const Edge &a, const Edge &b) {return a.cost < b.cost;};
	sort(edges.begin(), edges.end(), f);
	UnionFind uf(n);
	int res = 0;
	for (int i=0; i<m; i++) {
		Edge e = edges[i];
		if (!uf.same(e.u, e.v)) {
			uf.merge(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}
