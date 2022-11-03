template <unsigned int MOD>
struct Modint {
	unsigned int x;
	constexpr Modint(): x(0) {}
	template <typename T>
	constexpr Modint(T _x) noexcept : x((_x%=MOD)<0 ? _x+MOD : _x) {}
	constexpr Modint inv() const noexcept {
		ll a = x, b = MOD, u = 1, v = 0;
		while (b) {
			ll t = a / b;
			a -= t * b;
			swap(a, b);
			u -= t * v;
			swap(u, v);
		}
		return Modint(u);
	}
	constexpr Modint pow(ll n) const noexcept {
		Modint res = 1, a = *this;
		while (n > 0) {
			if (n&1) res *= a;
			a *= a;
			n >>= 1;
		}
		return res;
	}
	constexpr Modint operator+() const noexcept {return *this;}
	constexpr Modint operator-() const noexcept {return Modint()-*this;}
	constexpr Modint &operator++() noexcept {
		if (++x == MOD) x = 0;
		return *this;
	}
	constexpr Modint &operator--() noexcept {
		if (x-- == 0) x += MOD;
		return *this;
	}
	constexpr Modint operator++(int) noexcept {
		Modint res = *this;
		++*this;
		return res;
	}
	constexpr Modint operator--(int) noexcept {
		Modint res = *this;
		--*this;
		return res;
	}
	constexpr Modint &operator+=(const Modint &y) noexcept {
		if ((x+=y.x) >= MOD) x -= MOD;
		return *this;
	}
	constexpr Modint &operator-=(const Modint &y) noexcept {
		if (x < y.x) x += MOD;
		x -= y.x;
		return *this;
	}
	constexpr Modint &operator*=(const Modint &y) noexcept {
		x = (unsigned long long)x*y.x%MOD;
		return *this;
	}
	constexpr Modint &operator/=(const Modint &y) noexcept {return *this*=y.inv();}
	friend constexpr Modint operator+(const Modint &l, const Modint &r) {return Modint(l)+=r;}
	friend constexpr Modint operator-(const Modint &l, const Modint &r) {return Modint(l)-=r;}
	friend constexpr Modint operator*(const Modint &l, const Modint &r) {return Modint(l)*=r;}
	friend constexpr Modint operator/(const Modint &l, const Modint &r) {return Modint(l)/=r;}
	friend constexpr bool operator==(const Modint &l, const Modint &r) {return l.x==r.x;}
	friend constexpr bool operator!=(const Modint &l, const Modint &r) {return l.x!=r.x;}
	friend constexpr istream &operator>>(istream &is, Modint &y) {
		long long z;
		y = (is>>z, z);
		return is;
	}
	friend constexpr ostream &operator<<(ostream &os, const Modint &y) {return os<<y.x;}
};
