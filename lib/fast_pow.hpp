template <typename T>
T fast_pow(T x, ll n) {
	T res = 1;
	while (n) {
		if (n&1) res *= x;
		x *= x;
		n >>= 1;
	}
	return res;
}
