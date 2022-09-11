struct UnionFind {
	int fsize;
	vector<int> par, sz;
	UnionFind(int n): fsize(n), par(n), sz(n, 1) {
		for (int i=0; i<n; i++) par[i] = i;
	}
	int root(int x) {
		if (x != par[x]) par[x] = root(par[x]);
		return par[x];
	}
	bool merge(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (sz[x] > sz[y]) swap(x, y);
		par[x] = y;
		sz[y] += sz[x];
		fsize--;
		return true;
	}
	bool same(int x, int y) {return root(x)==root(y);}
	int size(int x) {return sz[root(x)];}
	int forest_size() {return fsize;}
};
