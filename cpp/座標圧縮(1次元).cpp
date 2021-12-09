/*
1次元の座標圧縮
配列vのそれぞれの要素について何番目に出現するかの座標圧縮: compress(v) 
昇順ソートして重複削除した配列を返す。座標復元に使う
*/

template <class T>
vector<T> compress(vector<T> &v) {
	vector<T> vals = v;
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int i=0; i<v.size(); i++) {
		v[i] = lower_bound(vals.begin(), vals.end(), v[i])-vals.begin();
	}
	return vals;
}
