template <typename T>
struct CRT {
	vector<T> rem, mod;
	void add(T r, T m) {
		rem.emplace_back(r);
		mod.emplace_back(m);
	}
	pair<T,T> calc() {
		T r = 0, m = 1;
		for (int i=0; i<(int)rem.size(); i++) {
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
			ext_gcd(m, mod[i], p, q, d);
			if ((rem[i]-r)%d != 0) return {0, 0};
			T t = (rem[i]-r)/d*p%(mod[i]/d);
			r += m*t;
			m *= mod[i]/d;
		}
		return {r<0?r+m:r, m};
	}
};
