/*
Dijkstra法
頂点sからの単一始点最短経路: dijkstra(頂点s, 隣接リスト{頂点, コスト})
verified: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5801897#1
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ALL(V) V.begin(), V.end()
using namespace std;

template <class T>
vector<T> dijkstra(int s, vector<vector<pair<int, T>>>& g) {
	vector<T> dis(g.size(), INT32_MAX);
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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int v, e, r;
	cin >> v >> e >> r;
	vector<vector<pair<int,int>>> g(v);
	while (e--) {
		int s, t, d;
		cin >> s >> t >> d;
		g[s].push_back({t, d});
	}
	for (int i: dijkstra(r, g)) {
		if (i == INT32_MAX) cout << "INF";
		else cout << i;
		cout << "\n";
	}
	return 0;
}
