#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

ll mod = 1000000007;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll q, l, r, x;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> l >> r >> x;
        
        if (x % 2 == 1 || x/2 < l or x/2 > r) {
            cout << 0 << endl;
        } else {
            cout << x/2 - l + 1 << endl;
        }
    }
    

    return 0;
}