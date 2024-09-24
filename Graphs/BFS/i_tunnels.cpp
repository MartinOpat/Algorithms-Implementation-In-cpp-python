#include<bits/stdc++.h>

using namespace std;

vector<int> bfs(map<int, set<int>>& g, int root, int n) {
    set<int> v;
    queue<int> q;
    q.emplace(root);
    vector<int> d(n, INT_MAX);
    d[root] = 0;  

    while(not q.empty()) {
        int node = q.front();
        q.pop();
        for (auto &ne: g[node]) {
            if (v.find(ne) == v.end()) {
                d[ne] = d[node]+1;
                v.insert(ne);
                q.emplace(ne);
            }
        }
    }

    return d;
}

int main() {
    int n, m, pa, pb;
    cin >> n >> m>>pa>>pb;

    map<int, set<int>> g;
    for (int i =0; i<m; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        g[p1].insert(p2);
        g[p2].insert(p1);
    }

    vector<int> d1 = bfs(g, pa, n);
    vector<int> d2 = bfs(g, pb, n);
    // for (auto& d: d1) cout << d << " ";
    // cout << endl;
    // for (auto& d: d2) cout << d << " ";
    // cout << endl;

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int temp = max(d1[i], d2[i]);
        ans = min(ans, temp);
    }

    cout << ans <<endl;
    return 0;
    

}