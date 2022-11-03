template <class T>
bool is_prime(T N) {
	if (N == 1) return false;
	for (T i=2; i*i<=N; i++) {
		if (N%i == 0) return false;
	}
	return true;
}
