/*
Dijkstra法

頂点sからの単一始点最短経路: dijkstra(頂点s, 隣接リスト{頂点, コスト})
*/

#include <bits/stdc++.h>
#define ll long long
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
