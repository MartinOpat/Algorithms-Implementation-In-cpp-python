// Use a GRAPH next time !!!!!!!!!!!!!!

/* 
Also these are good for debuggin:
11
10 4 3 1 1 -5 2 1 -1 -2 -5

12
1 1 2 3 3 2 1 3 0 0 1 -4


6
8 -1 -4 -2 -1 -13
*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

// const ll MAX_N = 200000ll;
// vector<ll> dp(MAX_N, 0);
map<int, set<int>*> circle_stuff = {};
map<int, set<int>> non_circle_stuff = {};
vector<set<int>*> avoiding_memory_leak;

void solve(int n, vector<int> &squares, int s, set<int> &curr_visited, set<int> &found_ms, vector<int> &dp) {
	if (s < 0 || s >= n) {
		return;
	}

	if (dp[s] != 0) {  // J: If I have assigned it, it is correct
        // found_ms.insert(squares[s]);
        if (non_circle_stuff.find(s) != non_circle_stuff.end()) {
            found_ms.insert(non_circle_stuff[s].begin(), non_circle_stuff[s].end());
        }

        if (circle_stuff.find(s) != circle_stuff.end()) {
            for (auto x: *circle_stuff[s]) {
                // cout << "marker= " << x << endl;
                found_ms.insert(x);
            }
        }
		return;
	}

	if (curr_visited.find(s) != curr_visited.end()) {
		set<int> *markers = new set<int> {squares[s]};
		int new_s = s + squares[s];
		while (new_s != s) {
			if ((*markers).find(squares[new_s]) == (*markers).end()) {
				(*markers).insert(squares[new_s]);
			}
			new_s += squares[new_s];
		}

		ll markers_count = (*markers).size();

		dp[s] = markers_count;
		new_s = s + squares[s];
        circle_stuff[s] = markers;
		while (new_s != s) {
            circle_stuff[new_s] = markers;
			dp[new_s] = markers_count;
			new_s += squares[new_s];
		}
        avoiding_memory_leak.push_back(markers);
		return;	 // circle done, we don't touch the circle again
	}

	curr_visited.insert(s);
	solve(n, squares, s + squares[s], curr_visited, found_ms, dp);

	if (dp[s] == 0) {  
        non_circle_stuff[s] = {squares[s]};
        if (s + squares[s] < 0 || s + squares[s] >= n) {
		    dp[s] = (found_ms.find(squares[s]) == found_ms.end() ? 1 : 0);
        } else {
		    dp[s] = dp[s + squares[s]] + (found_ms.find(squares[s]) == found_ms.end() ? 1 : 0);
            non_circle_stuff[s].insert(non_circle_stuff[s+squares[s]].begin(), non_circle_stuff[s+squares[s]].end());
        }
	}

	found_ms.insert(squares[s]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> squares(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> squares[i];
	}

    set<int> visited = {};
    set<int> found_ms = {};
    vector<int> dp(n, 0);
	for (int s = 0; s < n; s++) {
		if (dp[s] != 0) {
			continue;
		}

        visited = {};
        found_ms = {};
		solve(n, squares, s, visited, found_ms, dp);

        // for (auto x: non_circle_stuff) {
        //     cout << x.first << ": ";
        //     for (auto y: x.second) cout << y << " ";
        //     cout << endl;
        // }
        // cout << endl;
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << dp[i] << " ";
	// }
	// cout << endl;

	// cout << accumulate(dp.begin(), dp.begin() + n, 0ll) << endl;

    cout << "non-circle" << endl;
    for (auto x: non_circle_stuff) {
        cout << x.first << ": ";
        for (auto y: x.second) cout << y << " ";
        cout << endl;
    }

    cout << "circle" << endl;
    for (auto x: circle_stuff) {
        cout << x.first << ": ";
        for (auto y: *x.second) cout << y << " ";
        cout << endl;
    }
    cout << endl;
    

    ll ans = 0;
    for (auto x: non_circle_stuff) {
        ans += x.second.size();
    }
    for (auto x: circle_stuff) {  // Technically could be optimized
        ans += (*x.second).size();
    }

    cout << ans << endl;

    for (auto x: avoiding_memory_leak) {
        delete x;
    }
	return 0;
}