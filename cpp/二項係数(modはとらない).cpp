ll ncr(ll n, ll r) {
	ll res = 1;
	for (ll i=1; i<=r; i++) {
		res *= n--;
		res /= i;
	}
	return res;
}
