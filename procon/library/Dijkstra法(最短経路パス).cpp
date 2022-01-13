/*
Dijkstra法による最短経路パス

宣言: Dijkstra_ShortestPath hogehoge(始点, 隣接リスト)

頂点vまでの最短経路(存在しない場合は未定義): path(v)
始点からの単一始点最短経路長: distance()
*/

template <class T>
struct Dijkstra_ShortestPath {
	int s;
	vector<T> dis;
	vector<int> prev;
	vector<vector<pair<int, T>>> g;
	typedef pair<int,T> P;
	priority_queue<P, vector<P>, greater<P>> heap;
	Dijkstra_ShortestPath(int s, vector<vector<pair<int,T>>>& g)
		: s(s), g(g), prev(g.size(), -1), dis(g.size(), numeric_limits<T>::max()) {build();}
	void build() {
		dis[s] = 0;
		heap.push({0, s});
		while (!heap.empty()) {
			auto [v, pos] = heap.top();
			heap.pop();
			if (v < dis[pos]) continue;
			for (auto [to, cost]: g[pos]) {
				if (dis[to] > dis[pos]+cost) {
					dis[to] = dis[pos]+cost;
					prev[to] = pos;
					heap.push({dis[to], to});
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
	vector<T> distance() {
		return dis;
	}
};
