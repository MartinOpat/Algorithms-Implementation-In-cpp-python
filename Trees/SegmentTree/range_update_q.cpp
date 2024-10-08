#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

template <class T> struct Seg {
	int n;
	T ID = 0;
	vector<T> seg;
	T comb(T a, T b) { return a + b; }
	void init(int _n) {
		n = _n;
		seg.assign(n * 2, ID);
	}
	void pull(int p) { seg[p] = comb(seg[p * 2], seg[p * 2 + 1]); }
	void upd(int i, T val) {
		seg[i += n] += val;
		for (i /= 2; i; i /= 2) { pull(i); }
	}
	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ra = comb(ra, seg[l++]);
			if (r & 1) rb = comb(rb, seg[--r]);
		}
		return comb(ra, rb);
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	// sgt stores the difference array
	Seg<ll> sgt;
	sgt.init(n + 1);
	vector<int> ar(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
		sgt.upd(i, ar[i] - ar[i - 1]);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b;
			ll val;
			cin >> a >> b >> val;
			sgt.upd(a, val);
			sgt.upd(b + 1, -val);
		} else {
			int k;
			cin >> k;
			cout << sgt.query(1, k) << '\n';
		}
	}
}