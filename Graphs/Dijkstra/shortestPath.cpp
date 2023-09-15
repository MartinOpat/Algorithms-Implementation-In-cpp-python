#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

ll mod = 1000000007;
int inf = 1e9;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q, s;
    cin >> n >> m >> q >> s;
    while (!(n == 0 && m == 0 && q == 0 && s == 0)) {
        map<int, vector<pair<int, int>>> g;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].psh({v, w});
        }

        vector<int> dist(n, inf);
        dist[s] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({0, s});

        set<int> queries;
        vector<int> queries_help;
        int q_help = 0;
        while (q--) {
            int v;
            cin >> v;
            queries.insert(v);
            queries_help.psh(v);
            q_help++;
            // if (dist[v] == inf) cout << "Impossible" << endl;
            // else cout << dist[v] << endl;
        }

        set<int> visited;
        while (!pq.empty() && !queries.empty()) {
            int u = pq.top().second;
            int d = -pq.top().first;
            pq.pop();

            if (visited.find(u) != visited.end()) continue;

            queries.erase(u);
            visited.insert(u);

            for (auto e : g[u]) {
                int v = e.first;
                int w = e.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({-dist[v], v});
                }
            }
        }

        for (auto query: queries_help) {
            if (dist[query] == inf) cout << "Impossible" << endl;
            else cout << dist[query] << endl;
        }

        


        cin >> n >> m >> q >> s;
    }

    return 0;
}