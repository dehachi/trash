template <class T>
vector<pair<T,int>> prime_factorize(T N) {
    vector<pair<T,int>> res;
    for (T i=2; i*i<=N; i++) {
        if (N%i != 0) continue;
        int j = 0;
        while (N%i == 0) {
            j++;
            N /= i;
        }
        res.push_back({i,j});
    }
    if (N != 1) res.push_back({N,1});
    return res;
}
