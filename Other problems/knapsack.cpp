#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

#define PRINT_VEC(v) \
	for (int i = 0; i < v.size(); i++) cout << v[i] << (i < v.size() - 1 ? " " : "\n")

ll mod = 1000000007;

int max(int a, int b) { return (a > b) ? a : b; }

// Prints the items which are put in a knapsack of capacity W
void printknapSack(int W, int wt[], int val[], int n,  set<int>& ans) {
	int i, w;
	int K[n + 1][W + 1];

	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
								  K[i - 1][w - wt[i - 1]],
							  K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	// stores the result of Knapsack
	int res = K[n][W];
    // cout<< res << endl;

	w = W;
	for (i = n; i > 0 && res > 0; i--) {
		// either the result comes from the top
		// (K[i-1][w]) or from (val[i-1] + K[i-1]
		// [w-wt[i-1]]) as in Knapsack table. If
		// it comes from the latter one/ it means
		// the item is included.
		if (res == K[i - 1][w])
			continue;
		else {
			// This item is included.
			// cout << " " << wt[i - 1];
			ans.insert(i-1);

			// Since this weight is included its
			// value is deducted
			res = res - val[i - 1];
			w = w - wt[i - 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int c, n;
	while (cin >> c >> n) {
		int vals[n];
		int weights[n];
		for (int i = 0; i < n; i++) {
			cin >> vals[i] >> weights[i];
		}
		
		set<int> ans = {};
		printknapSack(c, weights, vals, n, ans);

		cout << ans.size() << endl;
		bool first = true;

		// Iterate through the set and print each element separated by a space
		for (const int& element : ans) {
			// Check if it's the first element
			if (first) {
				first = false;
			} else {
				std::cout << " ";
			}
			std::cout << element;
		}

		// Print a newline character at the end for formatting
		std::cout << std::endl;
	}

	return 0;
}