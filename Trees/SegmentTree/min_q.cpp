#include "bits/stdc++.h"

using namespace std;

#define vi vector<int>
#define mod 1000000007

template <class T, const T&(*op)(const T&, const T&)>
struct SegmentTree {
	int n; vector<T> tree; T id;
	SegmentTree(int _n, T _id) : n(_n), tree(2 * n, _id), id(_id) { }
	void update(int i, T val) {
		for (tree[i+n] = val, i = (i+n)/2; i > 0; i /= 2)
			tree[i] = op(tree[2*i], tree[2*i+1]);
	}
	T query(int l, int r) {
		T lhs = T(id), rhs = T(id);
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (  l&1 ) lhs = op(lhs, tree[l++]);
			if (!(r&1)) rhs = op(tree[r--], rhs);
		}
		return op(l == r ? op(lhs, tree[l]) : lhs, rhs);
	}
};

int main() {
    int n, q;
    cin >>n>>q;

    vi xs(n);
    for(auto&x:xs) cin>>x;

    // min seg-tree
    SegmentTree<int, min> st(n, INT_MAX);
    for(int i=0; i<n; i++) st.update(i, xs[i]);

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l-1, r-1) << endl;
    }

    return 0;
    
    
}