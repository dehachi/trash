template <class T>
vector<T> dijkstra(int s, vector<vector<pair<int,T>>> &g) {
	vector<T> dis(g.size(), numeric_limits<T>::max());
	typedef pair<T,int> P;
	priority_queue<P, vector<P>, greater<P>> pq;
	dis[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto [d, pos] = pq.top();
		pq.pop();
		if (d > dis[pos]) continue;
		for (auto &&[to, cost]: g[pos]) {
			if (dis[pos]+cost < dis[to]) {
				dis[to] = dis[pos] + cost;
				pq.push({dis[to], to});
			}
		}
	}
	return dis;
}
