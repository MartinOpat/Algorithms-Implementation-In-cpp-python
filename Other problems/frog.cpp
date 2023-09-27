#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

ll mod = 1000000007;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, m;
    cin >> n >> s >> m;
    s--;

    int tiles[n];
    for (int i = 0; i < n; i++) {
        cin >> tiles[i];
    }

    int hops = 0;
    set<int> visited = {};
    while (s >= 0 && s < n) {
        // cout << s << " " << tiles[s] << endl;
        if (tiles[s] == m) {
            cout << "magic" << endl;
            cout << hops << endl;
            return 0;
        }

        if (visited.find(s) != visited.end()) {
            cout << "cycle" << endl;
            cout << hops << endl;
            return 0;
        }

        visited.insert(s);
        hops++;
        s += tiles[s];
    }

    if (s < 0) {
        cout << "left" << endl;
    } else {
        cout << "right" << endl;
    }
    cout << hops << endl;

    return 0;
}