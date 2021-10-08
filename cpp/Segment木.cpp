/*
とりあえずrm
やる：

遅延のもつくる
*/
template <typename T>
struct SegmentTree {
	int n;
	vector<T> node;
	typedef function<T(T,T)> F;
	F f;
	T e;
	SegmentTree(int n, F f, T e) 
		: n(n), node(n*2, e), f(f), e(e) {}
	void set(int i, T x) {
		node[i+=n] = x;
		while (i) {
			i /= 2;
			node[i] = f(node[i*2], node[i*2+1]);
		}
	}
	T fold(int l, int r) {
		T res = e;
		for (l+=n, r+=n; l<r; l/=2, r/=2) {
			if (l%2 == 1) res = f(res, node[l++]);
			if (r%2 == 1) res = f(res, node[--r]);
		}
		return res;
	}
};
