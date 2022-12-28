#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T>
struct SegmentTree {
	int n, size;
	vector<T> dat;
	using F = function<T(T,T)>;
	T e;
	F f;
	SegmentTree(int _n, T _e, F _f): n(_n), e(_e), f(_f) {
		size = 1;
		while (size < _n) size <<= 1;
		dat.assign(size<<1, e);
	};
	void set(int i, T x) {
		dat[i+=size] = x;
		while (i >>= 1) {
			dat[i] = f(dat[i<<1], dat[(i<<1)|1]);
		}
	}
	T fold(int l, int r) {
		T res_l = e, res_r = e;
		for (l+=size, r+=size; l<r; l>>=1, r>>=1) {
			if (l&1) res_l = f(res_l, dat[l++]);
			if (r&1) res_r = f(dat[--r], res_r);
		}
		return f(res_l, res_r);
	}
	T &operator[](const int &i) {return &dat[i+size];}
};

constexpr int INF = 1<<30;

int N;
int P[2<<17], ans[2<<17];

void calc() {
	SegmentTree<int> seg(N+1, INF, [](int a, int b){return min(a,b);});
	SegmentTree<int> seg2(N+1, INF, [](int a, int b){return min(a,b);});
	for (int i=0; i<N; i++) {
		int s = seg.fold(0, P[i]), s2 = seg2.fold(P[i], N+1);
		if (s<INF) ans[i] = min(ans[i], P[i]+i+s);
		if (s2<INF) ans[i] = min(ans[i], -P[i]+i+s2);
		seg.set(P[i], -P[i]-i);
		seg2.set(P[i], P[i]-i);
	}
}

void solve() {
	cin >> N;
	for (int i=0; i<N; i++) cin >> P[i];
	fill(ans, ans+N, INF);
	calc();
	reverse(P, P+N);
	reverse(ans, ans+N);
	calc();
	for (int i=N-1; i>=0; i--) cout << ans[i] << (!i ? '\n' : ' ');
}

signed main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	solve();
	return 0;
}
