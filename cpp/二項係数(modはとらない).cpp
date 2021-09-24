ll ncr(ll n, ll r) {
	r = min(r, n-r);
	ll x = n, y = r;
	for (ll i=n-r+1; i<n; i++) x *= i;
	for (ll i=2; i<r; i++) y *= i;
	return x / y;
}
