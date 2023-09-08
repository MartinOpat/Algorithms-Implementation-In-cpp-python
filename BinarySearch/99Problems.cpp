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
    vector<int> ds;

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ds.psh(x);
    }

    sort(ds.begin(), ds.end());

    vector<int> ds_set = {ds[0]};
    vector<int> ds_count = {1};

    for (int i = 1; i < n; i++) {
        if (ds[i] == ds[i - 1]) {
            ds_count[ds_count.size() - 1]++;
        } else {
            ds_set.psh(ds[i]);
            ds_count.psh(1);
        }
    }

    int t, d;
    for (int i = 0; i < q; i++) {
        cin >> t >> d;
        if (ds_set.size() == 0) {
            cout << -1 << endl;
            continue;
        }

        // auto it = ds_set.lower_bound(d);
        auto it = lower_bound(ds_set.begin(), ds_set.end(), d);
        if (t == 1) {
            if (d >= ds_set[ds_set.size()-1]) {
                cout << -1 << endl;
                continue;
            }

            if (*it == d) {
                it++;
            }
        } else {
            if (ds_set[0] > d) {
                cout << -1 << endl;
                continue;
            }

            if (it == ds_set.end()) {
                it--;   
            }

            if (*it > d) {
                it--;
            }            
        }
        cout << *it << endl;

        if (ds_count[it - ds_set.begin()] > 1) {
            ds_count[it - ds_set.begin()]--;
        } else {
            ds_set.erase(it);
            ds_count.erase(ds_count.begin() + (it - ds_set.begin()));
        }
    }
    return 0;
}