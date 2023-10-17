#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back
#define IN(el, cont) cont.find((el)) != cont.end()

const ll MOD = 1000000007ll;  // 10e9+7

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> k;

	map<string, ll> attrs = {};
	string attrName;
	ll attrScore;
	for (ll i = 0; i < n; i++) {
		cin >> attrName >> attrScore;
        // cout << attrName << attrScore << endl;
		attrs[attrName] = attrScore;
	}

	ll l;
	cin >> l;
    map<string, vector<ll>> reqs = {};
	for (ll i = 0; i < l; i++) {
		cin >> attrName >> attrScore;
        
        if (reqs.find(attrName) != reqs.end()) {

        }
	}

    cout << max(0ll, k - req) << endl;

	return 0;
}