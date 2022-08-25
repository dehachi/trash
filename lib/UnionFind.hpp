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
