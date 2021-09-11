vector<ll> divisors(ll N) {
    vector<ll> res;
    for (ll i=1; i*i<=N; i++) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    std::sort(ALL(res));
    return res;
}
