#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pi>
#define vld vector<ld>

struct Tarjan {
	vvi &edges;
	int V, counter = 0, C = 0;
	vi n, l;
	vector<bool> vs;
	stack<int> st;
	Tarjan(vvi &e) : edges(e), V(e.size()), n(V, -1), l(V, -1), vs(V, false) {}
	void visit(int u, vi &com) {
		l[u] = n[u] = counter++;
		st.push(u);
		vs[u] = true;
		for (auto &&v : edges[u]) {
			if (n[v] == -1) visit(v, com);
			if (vs[v]) l[u] = min(l[u], l[v]);
		}
		if (l[u] == n[u]) {
			while (true) {
				int v = st.top();
				st.pop();
				vs[v] = false;
				com[v] = C;	 //<== ACT HERE
				if (u == v) break;
			}
			C++;
		}
	}
	int find_sccs(vi &com) {  // component indices will be stored in 'com'
		com.assign(V, -1);
		C = 0;
		for (int u = 0; u < V; ++u)
			if (n[u] == -1) visit(u, com);
		return C;
	}
	// scc is a map of the original vertices of the graph to the vertices of the SCC graph, scc_graph is its adjacency list. SCC indices and edges are stored in 'scc' and 'scc_graph'.
	void scc_collapse(vi &scc, vvi &scc_graph) {
		find_sccs(scc);
		scc_graph.assign(C, vi());
		set<pi> rec;  // recorded edges
		for (int u = 0; u < V; ++u) {
			assert(scc[u] != -1);
			for (int v : edges[u]) {
				if (scc[v] == scc[u] ||
					rec.find({scc[u], scc[v]}) != rec.end()) continue;
				scc_graph[scc[u]].push_back(scc[v]);
				rec.insert({scc[u], scc[v]});
			}
		}
	}
	// The number of edges needed to be added is max(sources.size(), sinks.())
	void findSourcesAndSinks(const vvi &scc_graph, vi &sources, vi &sinks) {
		vi in_degree(C, 0), out_degree(C, 0);
		for (int u = 0; u < C; u++) {
			for (auto v : scc_graph[u]) {
				in_degree[v]++;
				out_degree[u]++;
			}
		}
		for (int i = 0; i < C; ++i) {
			if (in_degree[i] == 0) sources.push_back(i);
			if (out_degree[i] == 0) sinks.push_back(i);
		}
	}
};


int main() {
    int n, m;
    cin >> n >> m;
    vld ps(n);
    for(auto&p:ps) cin>>p;

    vvi e(n, vi());
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        e[a].push_back(b);
    }

    Tarjan t(e);
    vi scc;
    vvi scc_graph;
    t.scc_collapse(scc, scc_graph);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " " << scc[i] << endl;
    // }
    // cout << endl;
    

    // for (int i = 0; i < scc_graph.size(); i++)
    // {
    //     cout << i << ": ";
    //     for(auto&x:scc_graph[i]) cout << x << " ";
    //     cout << endl;
    // }

    vvi scc_inv(scc_graph.size(), vi());
    for (int i = 0; i < n; i++)
    {
        scc_inv[scc[i]].push_back(i);
    }

    ld ans = 0;
    for (int i = 0; i < scc_inv.size(); i++)
    {
        if (scc_graph[i].size() > 0) continue;

        ld curr = 1;
        for (int j = 0; j < scc_inv[i].size(); j++)
        {
            // cout << ps[scc_inv[i][j]] << endl;
            curr *= 1-ps[scc_inv[i][j]];
        }
        ans = max(ans, curr);
        
    }
    cout << setprecision(18);
    cout << ans << endl;

    return 0;
}