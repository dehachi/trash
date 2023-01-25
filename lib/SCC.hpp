struct SCC {
	int n, fsize;
	vector<vector<int>> g, rg, scc;
	vector<int> vs, comp;
	vector<bool> used;
	SCC(int _n): n(_n), g(_n), rg(_n), comp(_n, -1), used(_n) {}
	void add_edge(int u, int v) {
		g[u].push_back(v);
		rg[v].push_back(u);
	}
	void dfs(int pos) {
		used[pos] = true;
		for (int &to: g[pos]) if (!used[to]) {
			dfs(to);
		}
		vs.push_back(pos);
	}
	void rdfs(int pos, int k) {
		comp[pos] = k;
		for (int &to: rg[pos]) if (comp[to] == -1) {
			rdfs(to, k);
		}
		scc[k].push_back(pos);
	}
	void build() {
		for (int i=0; i<n; i++) if (!used[i]) {
			dfs(i);
		}
		fsize = 0;
		for (int i=n-1; i>=0; i--) if (comp[vs[i]] == -1) {
			scc.push_back({});
			rdfs(vs[i], fsize++);
		}
	}
	void build(vector<vector<int>> &_g) {
		copy(_g);
		build();
	}
	int get(int x) {return comp[x];}
	bool same(int u, int v) {return comp[u] == comp[v];}
	int size() {return fsize;}
	vector<int> &operator[](int x) {return scc[x];}
	vector<vector<int>>::iterator begin() {return scc.begin();}
	vector<vector<int>>::iterator end() {return scc.end();}
};
