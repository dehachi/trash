ll ncr(ll n, ll r) {
	ll res = 1;
	for (ll i=1; i<=n; i++) {
		res *= r+i;
		res /= i;
	}
	return res;
}
