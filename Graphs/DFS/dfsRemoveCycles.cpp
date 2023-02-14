#include <bits/stdc++.h>

#define ll long long

using namespace std;


// O(V + E)
void removeCyc(ll node, unordered_map<ll, vector<pair<ll, ll>>>& neighs, vector<bool>& visited, vector<bool>& recStack, vector<ll>& ans) {
    if (!visited[node]) {
        visited[node] = true;
        recStack[node] = true;

        auto it = neighs.find(node);
        if (it != neighs.end()) {
            for (auto util: it->second) {
                ll nnode = util.first;
                if (recStack[nnode]) {
                    ans.push_back(util.second);
                } else if (!visited[nnode]) {
                    removeCyc(nnode, neighs, visited, recStack, ans);
                }
            }
        }
    }
    recStack[node] = false;
}


// Usage example
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    unordered_map<ll, vector<pair<ll, ll>>> neighs;
    ll u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        
        auto it = neighs.find(u);
        if (it == neighs.end()) {
            neighs.insert({u, vector<pair<ll, ll>> {pair<ll, ll> (v, i+1)}});
        } else {
            it->second.push_back(pair<ll, ll> (v, i+1));
        }
    }

    vector<bool> visited(n+1, false);
    vector<bool> recStack(n+1, false);
    ll root = 1;
    vector<ll> ans;
    
    for (int node = 1; node <= n; node++) {
        if (!visited[node]) {
            removeCyc(node, neighs, visited, recStack, ans);
        }
    }
    
    cout << ans.size() << endl;
    for (auto x: ans) cout << x << endl;
    
    return 0;
}