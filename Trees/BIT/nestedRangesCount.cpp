#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
struct FenwickTree {
    int n;
    vector<T> tree;
    
    FenwickTree(int n) : n(n) {
        tree.assign(n + 1, 0);
    }
    
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
    
    T query(int r) {
        T s = 0;
        for (; r > 0; r -= (r & -r)) {
            s += tree[r];
        }
        return s;
    }
    
    void update(int i, T v) {
        for (; i <= n; i += (i & -i)) {
            tree[i] += v;
        }
    }
};

struct Range {
    int x, y, idx;
};

int main() {
    int n;
    cin >> n;
    vector<Range> ranges(n);
    vector<int> contains(n), contained_by(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].idx = i;
    }

    // Sort by x, and by y in descending order
    sort(ranges.begin(), ranges.end(), [](const Range &a, const Range &b) {
        if (a.x == b.x) return a.y > b.y;
        return a.x < b.x;
    });
    
    // Coordinate compression for y values
    vector<int> ys(n);
    for (int i = 0; i < n; i++) {
        ys[i] = ranges[i].y;
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    
    auto get_compressed_y = [&](int y) {
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;
    };

    // Fenwick tree for counting ranges that contain others
    FenwickTree<int> fenwick(n);
    for (int i = 0; i < n; i++) {
        int y_compressed = get_compressed_y(ranges[i].y);
        contains[ranges[i].idx] = fenwick.query(y_compressed, n);
        fenwick.update(y_compressed, 1);
    }
    
    // Fenwick tree for counting ranges that are contained by others
    fenwick = FenwickTree<int>(n);
    for (int i = n - 1; i >= 0; i--) {
        int y_compressed = get_compressed_y(ranges[i].y);
        contained_by[ranges[i].idx] = fenwick.query(1, y_compressed);
        fenwick.update(y_compressed, 1);
    }
    
    // Output results
    for (int i = 0; i < n; i++) {
        cout << contained_by[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << endl;

    
    return 0;
}
