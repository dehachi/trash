template <typename T>
struct CombinationTable {
	int mx;
	vector<T> fac, ifac;
	CombinationTable(int _mx): mx(_mx+1), fac(_mx+1), ifac(_mx+1) {
		fac[0] = fac[1] = 1;
		for (int i=2; i<=mx; i++) fac[i] = fac[i-1]*i;
		ifac[mx] = 1/fac[mx];
		for (int i=mx; i>0; i--) ifac[i-1] = ifac[i]*i;
	}
	T C(int n, int k) {
		if (n<k || n<0 || k<0) return 0;
		return fac[n]*ifac[k]*ifac[n-k];
	}
	T H(int n, int k) {
		if (n == 0) return (ll)k==0;
		return C(n+k-1, k);
	}
	T P(int n, int k) {
		if (n < k) return 0;
		return fac[n]*ifac[n-k];
	}
};
