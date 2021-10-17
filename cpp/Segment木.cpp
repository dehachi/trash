/*
Segment木

宣言: SegmentTree(要素数, 二項演算子, 単位元)

i番目の要素をxに変更し祖先を更新: update(i, x)
i番目の要素をxに変更するだけ: set(i, x)
木全体を更新: build()
区間[l, r)で二項演算した値: fold(l, r)
*/

template <typename T>
struct SegmentTree {
	int n, logk, k;
	vector<T> node;
	typedef function<T(T,T)> F;
	F f;
	T e;
	SegmentTree(int n, F f, T e) 
		: n(n), f(f), e(e) {
			logk = 0;
			while ((1<<logk)<n) logk++;
			k = 1<<logk;
			node = vector<T>(2*k, e);
		}
	T operator[](int i) {return node[i+k];}
	void update(int i, T x) {
		node[i+=k] = x;
		for (int j=1; j<=logk; j++) {
			int p = i>>j;
			node[p] = f(node[p*2], node[p*2+1]);
		}
	}
	void set(int i, T x) {
		node[i+k] = x;
	}
	void build() {
		for (int i=k-1; i>0; i--) {
			node[i] = f(node[i*2], node[i*2+1]);
		}
	}
	T fold(int l, int r) {
		T res_l = e, res_r = e;
		l += k, r += k;
		while (l<r) {
			if (l%2 == 1) res_l = f(res_l, node[l++]);
			if (r%2 == 1) res_r = f(node[--r], res_r);
			l /= 2, r /= 2;
		}
		return f(res_l, res_r);
	}
};
