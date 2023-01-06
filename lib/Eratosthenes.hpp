struct Eratosthenes {
	int n;
	vector<bool> table;
	Eratosthenes(int _n): n(_n), table(_n+1, true) {
		table[0] = table[1] = false;
		for (int i=2; i<=_n; i++) if (table[i]) {
			for (int j=i*2; j<=_n; j+=i) table[j] = false;
		}
	}
	bool operator[](int x) {return table[x];}
};
