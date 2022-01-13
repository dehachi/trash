/*
桁和

nの各桁の値の総和
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T>
T ketawa(T N) {
    T res = 0;
    while (N > 0) {
        res += N%10;
        N /= 10;
    }
    return res;
}
