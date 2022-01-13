/*
素因数分解

nを(素因数, 指数) の形で素因数分解(素因数は昇順): prime_factorize(n)
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T>
vector<pair<T,int>> prime_factorize(T N) {
    vector<pair<ll,int>> res;
    for (T i=2; i+i<=N; i++) {
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
