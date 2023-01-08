struct RollingHash {
	using ull = unsigned long long;
	ull mod = (1ULL<<61)-1, base = 1571368660011369924ULL;
	vector<ull> hash, power;
	ull mul(ull a, ull b) {
		__uint128_t res = __uint128_t(a)*b;
		res = (res>>61)+(res&mod);
		return res>=mod ? res-mod : res;
	}
	RollingHash(string &s) {
		int n = s.size();
		hash.assign(n+1, 0);
		power.assign(n+1, 0);
		power[0] = 1;
		for (int i=0; i<n; i++) {
			hash[i+1] = mul(hash[i], base)+s[i];
			if (hash[i+1] >= mod) hash[i+1] -= mod;
			power[i+1] = mul(power[i], base);
		}
	}
	ull get(int l, int r) {
		ull res = hash[r]-mul(hash[l], power[r-l])+mod;
		return res>=mod ? res-mod : res;
	}
	int lcp(RollingHash &rh2, int l, int r, int l2, int r2) {
		int left = -1, right = min(r-l, r2-l2)+1;
		while (right-left > 1) {
			int mid = left+(right-left)/2;
			if (get(l, l+mid) == rh2.get(l2, l2+mid)) left = mid;
			else right = mid;
		}
		return left;
	}
};
