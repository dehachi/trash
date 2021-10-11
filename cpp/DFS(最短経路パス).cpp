/*
深さ優先探索による最短経路パス

宣言 Dfs_ShortestPath hogehoge(始点, 隣接リスト)

始点からvまでの最短経路パス(存在しない場合は未定義): path(v)
*/

struct Dfs_ShortestPath {
	int s;
	vector<int> prev;
	vector<vector<int>> g;
	Dfs_ShortestPath(int s, vector<vector<int>>& g)
		: s(s), g(g), prev(g.size(), -1) {build();}
	void build() {
		auto f = [&](auto self, int pos, int par) -> void {
			prev[pos] = par;
			for (int to: g[pos]) if (to != par) {
				self(self, to, pos);
			}
		};
		f(f, s, -1);
	}
	vector<int> path(int v) {
		vector<int> p;
		int i = v;
		while (i != -1) {
			p.push_back(i);
			i = prev[i];
		}
		reverse(p.begin(), p.end());
		return p;
	}
};
