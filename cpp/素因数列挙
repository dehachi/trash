vector<ll> prime_enumerate(ll N) {
    vector<ll> res;
    for (ll i=2; i+i<=N; i++) {
        if (N % i != 0) continue;
        while (N % i == 0) {
            N /= i;
        }
        res.push_back(i);
    }
    if (N != 1) res.push_back(1);
    return res;
}
