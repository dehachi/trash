/*
Dijkstra法による最短経路パス

宣言: Dijkstra_ShortestPath hogehoge(始点, 隣接リスト)

頂点vまでの最短経路(存在しない場合は未定義): path(v)
始点からの単一始点最短経路長: distance()
*/

struct Dijkstra_ShortestPath {
	int s;
	vector<ll> dis;
	vector<int> prev;
	vector<vector<pair<int, ll>>> g;
	typedef pair<ll, int> P;
	priority_queue<P, vector<P>, greater<P>> pq;
	Dijkstra_ShortestPath(int s, vector<vector<pair<int,ll>>>& g)
		: s(s), g(g), prev(g.size(), -1), dis(g.size(), LLONG_MAX) {build();}
	void build() {
		dis[s] = 0LL;
		pq.push({0LL, s});
		while (!pq.empty()) {
			auto [v, pos] = pq.top();
			pq.pop();
			if (v < dis[pos]) continue;
			for (auto [to, cost]: g[pos]) {
				if (dis[to] > dis[pos]+cost) {
					dis[to] = dis[pos]+cost;
					prev[to] = pos;
					pq.push({dis[to], to});
				}
			}
		}
	}
	vector<int> path(int v) {
		vector<int> p;
		int i=v;
		while (i != -1) {
			p.push_back(i);
			i = prev[i];
		}
		reverse(p.begin(), p.end());
		return p;
	}
	vector<ll> distance() {
		return dis;
	}
};
