template<typename T>
struct BIT {
	int n;
	vector<T> bit;
	BIT(): n(0) {}
	BIT(int _n): n(_n), bit(_n+1) {}
	void add(int i, T x) {
		i++;
		while (i <= n) {
			bit[i-1] += x;
			i += i&-i;
		}
	}
	T sum(int r) {
		T res = 0;
		while (r) {
			res += bit[r-1];
			r -= r&-r;
		}
		return res;
	}
	T sum(int l, int r) {return sum(r)-sum(l);}
};
