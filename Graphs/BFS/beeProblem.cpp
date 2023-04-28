#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

ll mod = 1000000007;

vector<pair<ll, ll>> neighsOdd(ll i, ll j, ll m, ll n) {
    vector<pair<ll, ll>> ans;
    if (j+1 < m) {
        ans.psh(pair<ll, ll>(i, j+1));

        if (i+1 < n)
            ans.psh(pair<ll, ll>(i+1, j+1));

        if (i-1 >= 0)
            ans.psh(pair<ll, ll>(i-1, j+1));
    }
    if (i-1 >= 0)
        ans.psh(pair<ll, ll>(i-1, j));

    if (i+1 < n)
        ans.psh(pair<ll, ll>(i+1, j));

    if (j-1 >= 0)
        ans.psh(pair<ll, ll>(i, j-1));

    return ans;
}

vector<pair<ll ,ll>> neighsEven(ll i, ll j, ll m, ll n) {
    vector<pair<ll, ll>> ans;
    if (i-1 >= 0) {
        ans.psh(pair<ll, ll>(i-1, j));

        if (j-1 >= 0)
            ans.psh(pair<ll, ll>(i-1, j-1));
    }
    if (j-1 >= 0)
        ans.psh(pair<ll, ll>(i, j-1));

    if (i+1 < n) {
        ans.psh(pair<ll, ll>(i+1, j));

        if (j-1 >= 0)
            ans.psh(pair<ll, ll>(i+1, j-1));
    }

    if (j+1 < m)
        ans.psh(pair<ll, ll>(i, j+1));

    return ans;

}

vector<ll> bfs(string graph, ll m, ll n) {
    queue<pair<ll, ll>> q;
    vector<ll> sizes;
    set<ll> visited;
    ll i, j, size, new_k;
    pair<ll, ll> temp;
    for (ll k = 0; k < m*n; k++) {
        if (graph.at(k) != '.' || visited.find(k) != visited.end()) continue;
        visited.insert(k);
        i = k / m;
        j = k % m;
        q.push(pair<ll, ll>(i, j));
        size = 0;
        while (q.size() != 0) {
            size++;
            temp = q.front();
            q.pop();
            i = temp.first;
            j = temp.second;

            // cout << i << " " << j << endl;

            if (i % 2 == 0) {
                for (pair<ll, ll> neigh: neighsEven(i, j, m ,n)) {
                    new_k = m*neigh.first + neigh.second;
                    if (graph.at(new_k) == '.' && visited.find(new_k) == visited.end()) {
                        visited.insert(new_k);
                        q.push(neigh);
                    }
                }
            } else {
                for (pair<ll, ll> neigh: neighsOdd(i, j, m ,n)) {
                    new_k = m*neigh.first + neigh.second;
                    if (graph.at(new_k) == '.' && visited.find(new_k) == visited.end()) {
                        visited.insert(new_k);
                        q.push(neigh);
                    }
                }
            }
        }
        sizes.psh(size);
    }
    return sizes;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll h, n, m;
    cin >> h >> n >> m;

    string maze = "";
    string x;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> x;
            maze.append(x);
        }
    }


    // cout << maze << endl;

    vector<ll> sizes = bfs(maze, m, n);
    sort(sizes.rbegin(), sizes.rend());

    // for (auto size: sizes) cout << size << " ";
    // cout << endl;

    ll ans = 0;
    while (h > 0) {
        h -= sizes[ans];
        ans++;
    }
    cout << ans << endl;

    return 0;
}