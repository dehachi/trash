/*
約数列挙

nの約数を昇順に列挙する: divisor_enumerate(n)
*/

vector<ll> divisor_enumerate(ll N) {
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
