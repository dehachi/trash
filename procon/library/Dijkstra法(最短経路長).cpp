/*
Dijkstra法による単一始点最短経路長

頂点sからの単一始点最短経路長: dijkstra_shortest_distance(頂点s, 隣接リスト{頂点, コスト})
*/

vector<ll> dijkstra_shortest_distance(int s, vector<vector<pair<int, ll>>>& g) {
	vector<ll> dis(g.size(), LLONG_MAX);
	dis[s] = 0LL;
	typedef pair<ll,int> P;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({0LL, s});
	while (!pq.empty()) {
		auto [v, pos] = pq.top();
		pq.pop();
		if (v < dis[pos]) continue;
		for (auto [to, cost]: g[pos]) {
			if (dis[to] > dis[pos] + cost) {
				dis[to] = dis[pos] + cost;
				pq.push({dis[to], to});
			}
		}
	}
	return dis;
}
