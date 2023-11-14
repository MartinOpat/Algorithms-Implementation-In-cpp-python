#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

ll mod = 1000000007;
int inf = 1e9;


vector<int> dijkstra(int n, int root, map<int, vector<pair<int, int>>>& g) {
	set<int> visited;
	vector<int> dist(n, inf);
    dist[root] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, root});
    while (!pq.empty()) {
        int node = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        if (visited.find(node) != visited.end()) continue;
        visited.insert(node);

        for (auto e : g[node]) {
            int neigh = e.first;
            int cost = e.second;
            if (dist[neigh] > dist[node] + cost) {
                dist[neigh] = dist[node] + cost;
                pq.push({-dist[neigh], neigh});
            }
        }
    }
    return dist;
}


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

        set<int> queries;
        vector<int> queries_help;
        int q_help = 0;
        while (q--) {
            int v;
            cin >> v;
            queries.insert(v);
            queries_help.psh(v);
            q_help++;

        }

        
		vector<int> dist = dijkstra(n, s, g);
        for (auto query: queries_help) {
            if (dist[query] == inf) cout << "Impossible" << endl;
            else cout << dist[query] << endl;
        }

        


        cin >> n >> m >> q >> s;
    }

    return 0;
}
