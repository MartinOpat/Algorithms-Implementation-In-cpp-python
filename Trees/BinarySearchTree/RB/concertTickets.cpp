#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpl vector<pl>
#define vpi vector<pi>
#define vld vector<ld>
#define in(el, cont) (cont.find(el) != cont.end())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()


int main() {
    int n,m;
    cin >> n >> m;

    vi hs(n), ts(m);
    for (auto &h: hs) cin >> h;
    for (auto &t: ts) cin >> t;

    map<int, int> hs2;
    for (int i=0; i<n; i++) {
        if (in(hs[i], hs2)) {
            hs2[hs[i]]++;
        } else {
            hs2[hs[i]] = 1;
        }
    }

    for (int i=0; i<m; i++) {
        auto it = hs2.upper_bound(ts[i]);
        if (it == hs2.begin()) {
            cout << -1 << endl;
        } else {
            it = prev(it);
            cout << it->first << endl;
            hs2[it->first]--;
            if (hs2[it->first] == 0)
                hs2.erase(it);
        }
    }
    
    return 0;
    
}