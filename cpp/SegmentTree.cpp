/*
とりあえずrmp
やる：
抽象化
遅延のもつくる
*/
struct SegmentTree {
	int n;
	vector<int> node;
	SegmentTree(int n) : n(n), node(n*2, INT32_MAX) {}
	void set(int i, int x) {
		node[i+=n] = x;
		while (i) {
		    i /= 2;
			node[i] = min(node[i*2], node[i*2+1]);
		}
	}
	int fold(int l, int r) {
		int res = INT32_MAX;
		for (l+=n, r+=n; l<r; l/=2, r/=2) {
			if (l%2 == 1) res = min(res, node[l++]);
			if (r%2 == 1) res = min(node[--r], res);
		}
		return res;
	}
};
