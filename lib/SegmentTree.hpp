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
	T &operator[](int i) {return dat[i+size];}
};
