template <typename T>
struct SegmentTree {
	int n;
	vector<T> dat;
	using F = function<T(T,T)>;
	F f;
	T e;
	SegmentTree(int _n, F _f, T _e): n(_n), dat((n<<1)|1, _e), f(_f), e(_e) {};
	void set(int i, T x) {
		dat[i+=n] = x;
		while (i) {
			i >>= 1;
			dat[i] = f(dat[i<<1], dat[(i<<1)|1]);
		}
	}
	T fold(int l, int r) {
		T res_l = e, res_r = e;
		for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
			if (l&1) res_l = f(res_l, dat[l++]);
			if (r&1) res_r = f(dat[--r], res_r);
		}
		return f(res_l, res_r);
	}
	T operator[](const int &i) const {return dat[i+n];}
};
