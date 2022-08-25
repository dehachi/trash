template <typename T>
struct BIT {
	int n;
	vector<T> bit;
	BIT(int _n): n(_n+1), bit(_n+1) {}
	void add(int i, T x) {
		i++;
		while (i < n) {
			bit[i] += x;
			i += i&-i;
		}
	}
	T sum(int r) {
		r++;
		T res = 0;
		while (r > 0) {
			res += bit[r];
			r -= r&-r;
		}
		return res;
	}
	T sum(int l, int r) {
		return sum(r)-sum(l-1);
	}
};
