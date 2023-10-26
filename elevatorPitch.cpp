#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back
#define IN(el, cont) (cont.find(el) != cont.end())

const ll MOD = 1000000007ll;  // 10e9+7

vector<pair<int, int>> get_adjacent(int h, int w, pair<int, int> node) {
	vector<pair<int, int>> adjacent;
	int x = node.first, y = node.second;

	if (x - 1 >= 0) {
		adjacent.push_back({x - 1, y});
	}

	if (y + 1 < h) {
		adjacent.push_back({x, y + 1});
	}

	if (x + 1 < w) {
		adjacent.push_back({x + 1, y});
	}

	if (y - 1 >= 0) {
		adjacent.push_back({x, y - 1});
	}

	return adjacent;
}

int is_local_maxima(int h, int w, vector<vector<int>>& plan, pair<int, int> root) {
    queue<pair<int, int>> q_eq, q_sm;
    q_eq.emplace(root);
    int val = plan[root.second][root.first];
    int ans = 1;

    // Determine the answer
    while (!q_eq.empty()) {
        pair<int, int> node = q_eq.front();
        q_eq.pop();

        if (plan[node.second][node.first] == -1) {
            continue;
        }

        // cout << "equal node: " << node.first << " " << node.second << endl;

        plan[node.second][node.first] = -1;

        for (auto x: get_adjacent(h, w, node)) {
            if (plan[x.second][x.first] > val) {
                ans = 0;
            } else if (plan[x.second][x.first] == val) {
                q_eq.emplace(x);
            } else if (plan[x.second][x.first] > 1) {
                q_sm.emplace(x);
            }
        }
    }

    // make sure all smaller ones are tagges as visited
    while (!q_sm.empty()) {
        pair<int, int> node = q_sm.front();
        q_sm.pop();

        if (plan[node.second][node.first] == -1) {
            continue;
        }

        // cout << "small node: " << node.first << " " << node.second << endl;


        for (auto x: get_adjacent(h, w, node)) {
            if (node.second == 2  and node.first == 2) {
                // cout << "wtf: " << x.first << " " << x.second << " " << plan[x.second][x.first] << endl;
            }
            if (plan[x.second][x.first] > 1 and plan[x.second][x.first] <= plan[node.second][node.first]) {
                q_sm.emplace(x);
                // cout << "indeed smaller" << endl;
            }
        }
        plan[node.second][node.first] = -1;
    }

    return ans;
}

int bfs(int h, int w, vector<vector<int>>& plan, pair<int, int> root) {
	queue<pair<int, int>> q;
	q.emplace(root);
	int ans = 0;

	// cout << "root: " << root.first << " " << root.second << endl;

	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();

        if (plan[node.second][node.first] == -1) {
            continue;
        }

        // cout << "node: " << node.first << " " << node.second << " queue size " << q.size() << endl;

		if (plan[node.second][node.first] > 1) {
			ans += is_local_maxima(h, w, plan, node);
		}

		plan[node.second][node.first] = -1;	 // visisted

		for (auto x : get_adjacent(h, w, node)) {
            // cout << x.first << " " << x.second << ", " <<  endl;
			if (plan[x.second][x.first] != -1) {
				q.emplace(x);
			}
		}
        // cout << endl;
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int h, w;
	cin >> h >> w;

	vector<vector<int>> plan(h, vector<int>(w, 0));

	pair<int, int> root = {0, 0};
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> plan[i][j];

			if (plan[i][j] == 1) {
				plan[i][j] = 0;
			}

			if (plan[i][j] == 0) {
				root = {j, i};
			}
		}
	}

    int ans = bfs(h, w, plan, root);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (plan[i][j] != -1) {
                ans += bfs(h, w, plan, {j, i});
            }
		}
	}

    cout << ans << endl;

	return 0;
}