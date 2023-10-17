#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back
#define IN(el, cont) (cont.find(el) != cont.end())

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
		attrs[attrName] = attrScore;
	}

	ll l;
	cin >> l;
    map<string, vector<ll>> reqs = {};
    map<string, pair<ll, ll>> treshs = {};
	for (ll i = 0; i < l; i++) {
		cin >> attrName >> attrScore;
        
        if (IN(attrName, reqs)) {
            reqs[attrName].psh(attrScore);
            if (treshs[attrName].first < attrScore) {
                treshs[attrName] = {attrScore, 1ll};
            } else if (treshs[attrName].first == attrScore) {
                treshs[attrName].second++;
                
            }
        } else {
            reqs[attrName] = vector<ll>{attrScore};
            treshs[attrName] = {attrScore, 1ll};
        }
	}

    ll mostTests = 0;
    string mostTestsAttr = "";
    for (auto x: treshs) {
        attrName = x.first;

        if (attrs[attrName] < treshs[attrName].first) {
            k -= treshs[attrName].first - attrs[attrName];
            attrs[attrName] = treshs[attrName].first;
        }

        if (mostTests < reqs[attrName].size()) {
            mostTests = reqs[attrName].size();
            mostTestsAttr = attrName;
        }
    }

    if (k < 0) {
        cout << 0 << endl;
        return 0;
    }

    ll currAttrIncr;
    priority_queue<pair<int, string>> incrOrder;
    for (auto x: attrs) {
        attrName = x.first;
        attrScore = x.second;

        if (!IN(attrName, treshs)) {
            continue;
        }

        if (attrScore == treshs[attrName].first) {
            currAttrIncr = attrScore*treshs[attrName].second + reqs[attrName].size();
        } else {
            continue;
        }

        incrOrder.emplace(currAttrIncr, attrName);
    }
    
    while (k && !incrOrder.empty() && (incrOrder.top()).first > mostTests) {
        string bestAttr = (incrOrder.top()).second;
        incrOrder.pop();

        k--;
        attrs[bestAttr]++;
    }

    attrs[mostTestsAttr] += k;

    ll ans = 0ll;
    for (auto x: reqs) {
        attrName = x.first;

        ans += attrs[attrName]*(reqs[attrName].size());
        if (attrs[attrName] == treshs[attrName].first) {
            ans -= attrs[attrName]*treshs[attrName].second;
        }
    }

    cout << ans << endl;

	return 0;
}