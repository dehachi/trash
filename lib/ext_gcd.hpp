template <class T>
pair<T,T> ext_gcd(T a, T b) {
	T x = 1, y = 0, u = 0, v = 1;
	while (b) {
		T p = a/b, q = a%b, r = x-u*p;
		x = u, u = r;
		r = y-v*p;
		y = v, v = r;
		a = b, b = q;
	}
	return {x, y};
}
