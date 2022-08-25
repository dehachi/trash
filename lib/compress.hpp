template <class T>
vector<T> compress(vector<T> &v) {
	vector<T> vals = v;
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int i=0; i<(int)v.size(); i++) {
		v[i] = lower_bound(vals.begin(), vals.end(), v[i])-vals.begin();
	}
	return vals;
}
