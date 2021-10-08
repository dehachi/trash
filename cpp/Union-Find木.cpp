/*
Union-Find木

宣言: UnionFind hogehoge(頂点数)

構築(自動): build(頂点数)
頂点xの根を求める: root(頂点x)
頂点xと頂点yの木を結合: merge(頂点x, 頂点y)
頂点xと頂点yが同じ木に属するか: same(頂点x, 頂点y)
頂点xの属する木の頂点数: size(頂点x)
森に生えてる木の本数: forest_size(頂点x)
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
