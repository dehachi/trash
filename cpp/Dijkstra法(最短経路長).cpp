/*
Dijkstra法による単一始点最短経路長

頂点sからの単一始点最短経路長: dijkstra_shortest_distance(頂点s, 隣接リスト{頂点, コスト})
*/

template <class T>
vector<T> dijkstra_shortest_distance(int s, vector<vector<pair<int, T>>>& g) {
	vector<T> dis(g.size(), numeric_limits<T>::max());
	dis[s] = 0;
	typedef pair<int,T> P;
	priority_queue<P, vector<P>, greater<P>> heap;
	heap.push({0, s});
	while (!heap.empty()) {
		auto[v, pos] = heap.top();
		heap.pop();
		if (v < dis[pos]) continue;
		for (P e: g[pos]) {
			auto[to, cost] = e;
			if (dis[to] > dis[pos] + cost) {
				dis[to] = dis[pos] + cost;
				heap.push({dis[to], to});
			}
		}
	}
	return dis;
}
