#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int convert_cd(const string &s) {
  int k = stoi(s.substr(1));
  if (s[0] == 'D')
    k += 100;
  return k;
}

struct vote {
  int id;
  int t;
  int k;
};

bool bfs(vector<int> adj[502], vector<int> &parent, int rGraph[502][502]) {
  vector<bool> visited(502, false);
  queue<int> q;
  q.emplace(0);
  parent[0] = -1;
  visited[0] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int n : adj[u]) {
      if (!visited[n] && rGraph[u][n] > 0) {
        parent[n] = u;
        if (n == 501) {
          // sink
          return true;
        }
        q.emplace(n);
        visited[n] = true;
      }
    }
  }
  return false;
}

int fordFulkerson(vector<int> edges[502]) {
  int u, v;
  int rGraph[502][502] = {0};
  vector<int> adj[502];

  for (u = 0; u < 502; ++u) {
    for (int n : edges[u]) {
      rGraph[u][n] = 1;
      adj[u].push_back(n);
      adj[n].push_back(u);
    }
  }

  vector<int> parent(502, 0);
  int max_flow = 0;

  while (bfs(adj, parent, rGraph)) {
    int path_flow = INT_MAX;
    for (v = 501; v != 0; v = parent[v]) {
      u = parent[v];
      path_flow = min(path_flow, rGraph[u][v]);
    }

    for (v = 501; v != 0; v = parent[v]) {
      u = parent[v];
      rGraph[u][v] -= path_flow;
      rGraph[v][u] += path_flow;
    }

    max_flow += path_flow;
  }

  return max_flow;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  while (n--) {
    int c, d, v;
    cin >> c >> d >> v;

    vector<int> edges[502];
    vector<vote> voters;

    // source = 0
    // cats = 1-100, dogs = 101-200
    // sink = 501
    string ks, ts;
    int k, t;

    int total_voters = v;
    while (v--) {
      cin >> ks >> ts;
      k = convert_cd(ks);
      t = convert_cd(ts);
      int voter_id = v + 1;

      if (ks[0] == 'C')
        edges[0].push_back(voter_id);
      else
        edges[voter_id].push_back(501);

      for (const auto &prev : voters) {
        if (prev.t == k || prev.k == t) {
          if (ks[0] == 'C')
            edges[voter_id].push_back(prev.id);
          else
            edges[prev.id].push_back(voter_id);
        }
      }
      voters.push_back({voter_id, t, k});
    }

    cout << total_voters - fordFulkerson(edges) << "\n";
  }

  return 0;
}
