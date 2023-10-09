#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

const ll MOD = 1000000007ll;  // 10e9+7
int inf = 1e9;

vector<int> maxDijkstra(map<int, vector<pair<int, int>>> g, int n) {
	int s = 0;	// always start from 0
	vector<int> dist(n, 0);
	dist[s] = inf;
	priority_queue<pair<int, int>> pq;
	pq.push({dist[s], s});

	vector<int> parents(n, -1);
	parents[0] = 0;
	set<int> visited;
	while (!pq.empty()) {
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		if (visited.find(u) != visited.end()) continue;

		visited.insert(u);

		for (auto e : g[u]) {
			int v = e.first;
			if (visited.find(v) != visited.end()) continue;
			int w = e.second;
			if (dist[v] < min(dist[u], w)) {
				dist[v] = min(dist[u], w);
				parents[v] = u;
				pq.push({dist[v], v});
			}
		}
		// for (auto x: parents) {
		//     cout << x << " ";
		// }
		// cout << endl;
	}

	int node = n - 1;
	vector<int> path = {node};

	// for (auto x: parents) {
	//     cout << x << " ";
	// }
	// cout << endl;
	// for (auto x: dist) {
	//     cout << x << " ";
	// }
	// cout << endl;

	while (parents[node] != node) {
		node = parents[node];
		path.psh(node);
	}

	// for (auto x: path) cout << x << " ";
	// cout << endl;

	return path;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<int, vector<pair<int, int>>> g;
	map<pair<int, int>, int> streetNums;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].psh({v, w});
		g[v].psh({u, w});

		streetNums.insert({pair<int, int>{u, v}, i});
		streetNums.insert({pair<int, int>{v, u}, i});
	}

	vector<int> path = maxDijkstra(g, n);
	set<int> edges = {};
	set<int> blockedEdges = {};
	for (int i = 0; i < path.size(); i++) {
		// edges.insert(streetNums.at(pair<int, int>{path[i], path[i + 1]}));

		for (auto u : g[path[i]]) {
            // cout << u.first << " " << path[i];
			if (u.first != path[min(i+1, (int)path.size()-1)] && u.first != path[max(i-1, 0)]) {
                // cout << " -> Here";
				blockedEdges.insert(streetNums.at(pair<int, int>{path[i], u.first}));
			}
            // cout << endl;
		}
	}

    if (blockedEdges.empty()) {
        cout << "none" << endl;
        return 0;
    }

	for (auto it = blockedEdges.begin(); it != blockedEdges.end(); it++) {
		cout << *it;

        if (next(it) != blockedEdges.end()) {
            cout << " ";
        } else {
            cout << endl;
        }
	}

	return 0;
}