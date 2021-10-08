/*
二項係数

nCrを求める: ncr(n, r)
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ncr(ll n, ll r) {
	ll res = 1;
	for (ll i=1; i<=r; i++) {
		res *= n--;
		res /= i;
	}
	return res;
}
