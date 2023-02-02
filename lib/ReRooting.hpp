template <typename T>
struct ReRooting {
	int n;
	vector<vector<int>> G;
	vector<vector<T>> memo;
	vector<T> dp;
	T e;
	using F = function<T(T,T)>;
	using F2 = function<T(T,int)>;
	F merge;
	F2 add_root, f;
	ReRooting(int _n, T _e, F _merge, F2 _add_root, F2 _f):
		n(_n), e(_e), merge(_merge), add_root(_add_root), f(_f) {
			G.resize(_n);
			memo.resize(_n);
			dp.assign(_n, _e);
	}
	void add_edge(int u, int v) {
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	T dfs(int pos, int par) {
		T res = e;
		int m = G[pos].size();
		for (int i=0; i<m; i++) if (G[pos][i] != par) {
			memo[pos][i] = dfs(G[pos][i], pos);
			res = merge(res, f(memo[pos][i], G[pos][i]));
		}
		return add_root(res, pos);
	}
	void reroot(int pos, int par, T t) {
		int m = G[pos].size();
		for (int i=0; i<m; i++) if (G[pos][i] == par) {
			memo[pos][i] = t;
			break;
		}
		vector<T> memo_r(m+1, e);
		for (int i=m-1; i>=0; i--) {
			memo_r[i] = merge(memo_r[i+1], f(memo[pos][i], G[pos][i]));
		}
		T memo_l = e;
		for (int i=0; i<m; i++) {
			int to = G[pos][i];
			if (to != par) {
				reroot(to, pos, add_root(merge(memo_l, memo_r[i+1]), pos));
			}
			memo_l = merge(memo_l, f(memo[pos][i], to));
		}
		dp[pos] = add_root(memo_l, pos);
	}
	void build() {
		for (int i=0; i<n; i++) memo[i].assign(G[i].size(), e);
		dfs(0, -1);
		reroot(0, -1, e);
	}
	T &operator[](int i) {return dp[i];}
};
