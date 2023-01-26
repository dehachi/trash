template <typename T>
struct CRT {
	T rem, mod;
	CRT(): rem(0), mod(1) {}
	void add(T r, T m) {
		auto ext_gcd = [](T a, T b, T &x, T &y, T &d) -> void {
			x = 1, y = 0;
			T u = 0, v = 1;
			while (b) {
				T p = a/b, q = a%b, r = x-u*p;
				x = u, u = r;
				r = y-v*p;
				y = v, v = r;
				a = b, b = q;
			}
			d = a;
		};
		T p, q, d;
		ext_gcd(mod, m, p, q, d);
		if ((r-rem)%d != 0) {
			rem = mod = 0;
			return;
		}
		rem += mod*((r-rem)/d*p%(m/d));
		mod *= m/d;
	}
	pair<T,T> get() {return {rem<0?rem+mod:rem, mod};}
};
