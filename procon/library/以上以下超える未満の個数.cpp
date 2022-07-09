template <class T>
int x_or_more(vector<T> &v, T x) {
	auto iter_lower = lower_bound(v.begin(), v.end(), x);
	int idx_lower = distance(v.begin(), iter_lower);
	return (int)v.size() - idx_lower;
}

template <class T>
int x_or_less(vector<T> &v, T x) {
	auto iter_upper = upper_bound(v.begin(), v.end(), x);
	int idx_upper = distance(v.begin(), iter_upper);
	return idx_upper;
}

template <class T>
int over_x(vector<T> &v, T x) {
	auto iter_upper = upper_bound(v.begin(), v.end(), x);
	int idx_upper = distance(v.begin(), iter_upper);
	return (int)v.begin() - idx_upper;
}

template <class T>
int under_x(vector<T> &v, T x) {
	auto iter_lower = lower_bound(v.begin(), v.end(), x);
	int idx_lower = distance(v.begin(), iter_lower);
	return idx_lower;
}
