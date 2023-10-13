#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

ll mod = 1000000007;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    map<int, int> ds;

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (ds.find(x) == ds.end()) {
            ds[x] = 1;
        } else {
            ds[x]++;
        }
    }

    int t, d;
    for (int i = 0; i < q; i++) {
        cin >> t >> d;
        if (ds.size() == 0) {
            cout << -1 << endl;
            continue;
        }

        auto it = ds.lower_bound(d);
        if (t == 1) {
            if (d >= (*prev(ds.end())).first) {
                cout << -1 << endl;
                continue;
            }
            if ((*it).first == d) {
                it = next(it);
            }
        } else {
            if ((*ds.begin()).first > d) {
                cout << -1 << endl;
                continue;
            }

            if (it == ds.end()) {
                it = prev(it);
            }

            if ((*it).first > d) {
                it = prev(it);
            }            
        }
        cout << (*it).first << endl;

        if (ds[(*it).first] > 1) {
            ds[(*it).first]--;
        } else {
            ds.erase(it);
            // ds_count.erase(ds_count.begin() + (it - ds_set.begin()));
        }
    }
    return 0;
}