/*
セグメント木

宣言: SegmentTree(要素数, 二項演算子, 単位元)

i番目の要素をxに変更し祖先を更新: update(i, x)
i番目の要素をxに変更するだけ: set(i, x)
木全体を更新: build()
区間[l, r)で二項演算した値: fold(l, r)
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
	void update(int i, T x) {
		node[i+=n] = x;
		while (i) {
			i /= 2;
			node[i] = f(node[i*2], node[i*2+1]);
		}
	}
	void set(int i, T x) {
		node[i+n] = x;
	}
	void build() {
		for (int i=n-1; i>0; i--) {
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
