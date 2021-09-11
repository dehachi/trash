vector<pair<ll,int>> prime_factorize(ll N) {
    vector<pair<ll,int>> res;
    for (ll i=2; i+i<=N; i++) {
        if (N % i != 0) continue;
        int j = 0;
        while (N % i == 0) {
            j++;
            N /= i;
        }
        res.push_back({i,j});
    }
    if (N != 1) res.push_back({N,1});
    return res;
}
