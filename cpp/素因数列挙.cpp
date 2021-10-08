/*
素因数列挙

nの素因数を昇順に列挙: prime_enumerate(n)
*/

template <class T>
vector<T> prime_enumerate(T N) {
    vector<T> res;
    for (T i=2; i+i<=N; i++) {
        if (N % i != 0) continue;
        while (N % i == 0) {
            N /= i;
        }
        res.push_back(i);
    }
    if (N != 1) res.push_back(N);
    return res;
}
