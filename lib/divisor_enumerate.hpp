template <class T>
vector<T> divisor_enumerate(T N, bool _sort=true) {
	vector<T> res;
	for (T i=1; i*i<=N; i++) {
		if (N%i == 0) {
			res.push_back(i);
			if (N/i != i) res.push_back(N/i);
		}
	}
	if (_sort) std::sort(res.begin(), res.end());
	return res;
}
