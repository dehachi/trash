/*
深さ優先探索による単一始点最短経路長

頂点sから全頂点への最短経路長: dfs_shortest_distance(s, 隣接リスト)
*/

vector<int> dfs_shortest_distance(int s, vector<vector<int>>& g) {
	int n = g.size();
	vector<int> dis(n);
	auto f = [&](auto self, int pos, int par, int d) -> void {
		dis[pos] = d;
		for (int to: g[pos]) if (to != par) {
			self(self, to, pos, d+1);
		}
	};
	f(f, s, -1, 0);
	return dis;
}
