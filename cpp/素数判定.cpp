/*
素数判定

nの素数判定: is_prime(n)
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T>
bool is_prime(T N) {
    if (N == 1) return false;
    for (T i=2; i*i<=N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}
