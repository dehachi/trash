/*
約数列挙

nの約数を昇順に列挙する: divisor_enumerate(n)
*/

template <class T>
vector<T> divisor_enumerate(T N) {
    vector<T> res;
    for (T i=1; i*i<=N; i++) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    std::sort(ALL(res));
    return res;
}
