/*
深さ優先探索によるオイラーツアーの頂点経路

根をsとしてオイラーツアー: euler_tour_path(s, 隣接リスト)
*/

vector<int> euler_tour_path(int s, vector<vector<int>>& g) {
	vector<int> res;
	auto f = [&](auto self, int pos, int par) -> void {
		res.push_back(pos);
		for (int to: g[pos]) if (to != par) {
			self(self, to, pos);
			res.push_back(pos);
		}
	};
	f(f, s, -1);
	return res;
}
