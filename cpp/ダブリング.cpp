/*
ダブリング
宣言: Doubling hogehoge(要素数, logk, 全要素の次に到達する要素)

構築(自動): build(要素数, logk, 全要素の次に到達する要素)
sからk回移動した要素: calc(s, k)
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T>
struct Doubling {
	int n;
	int logk;
	vector<vector<T>> dbl;
	Doubling(int n, int logk, vector<T> &v)
		: n(n), logk(logk) {build(v);}
	void build(vector<T>& v) {
		dbl.assign(logk, vector<T>(n));
		dbl[0] = v;
		for (int i=0; i<logk-1; i++) {
			for (int j=0; j<n; j++) {
				dbl[i+1][j] = dbl[i][dbl[i][j]];
			}
		}
	}
	template <class U>
	T calc(T s, U k) {
		T res = s;
		for (int i=0; k>0; i++) {
			if (k%2 == 1) res = dbl[i][res];
			k /= 2;
		}
		return res;
	}
};
