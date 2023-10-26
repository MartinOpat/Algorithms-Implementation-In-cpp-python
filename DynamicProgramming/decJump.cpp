#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

const ll MOD = 1000000007ll;  // 10e9+7
const ll NEG_INF = -1000000000ll * 3000ll + 1ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	vector<ll> ps(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> ps[i];
	}

	vector<vector<ll>> dp(n, vector<ll>(n, NEG_INF));

	// init first column
	vector<ll> maxEls(n, NEG_INF);
	for (ll i = 0; i < n; i++) {
		dp[i][0] = ps[0];
	}
	maxEls[0] = ps[0];

	for (ll i = n - 1; i >= 0; i--) {
		for (ll j = i + 1; j < n; j++) {
			if (maxEls[j - (i + 1)] > NEG_INF and 1) {
				dp[i][j] = ps[j] + maxEls[j - (i + 1)];
				maxEls[j] = max(maxEls[j], dp[i][j]);
			}
		}
	}

	// cout << endl;
	// for (auto x: dp) {
	// 	for (auto y: x) {
	// 		cout << y << " ";
	// 	}
	// 	cout << endl;
	// }

	// ll ans = dp[0][n - 1];
	// for (ll i = 1; i < n; i++) {
	// 	ans = max(ans, dp[i][n - 1]);
	// }

	cout << maxEls[n-1] << endl;

	return 0;
}
