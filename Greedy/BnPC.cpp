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
        // cout << attrName << attrScore << endl;
		attrs[attrName] = attrScore;
	}

    // for (auto it = attrs.begin(); it != attrs.end(); it = next(it)) {
    //     cout << (*it).first << endl;
    // }

	ll l;
	cin >> l;
    map<string, vector<ll>> reqs = {};
    map<string, ll> treshs = {};
	for (ll i = 0; i < l; i++) {
		cin >> attrName >> attrScore;
        
        if (IN(attrName, reqs)) {
            reqs[attrName].psh(attrScore);
            treshs[attrName] = max(treshs[attrName], attrScore);
        } else {
            reqs[attrName] = vector<ll>{attrScore};
            treshs[attrName] = attrScore;
        }

        if (attrs[attrName] < treshs[attrName]) {
            k -= treshs[attrName] - attrs[attrName];
            attrs[attrName] = treshs[attrName];
        }
	}

    if (k < 0) {
        cout << 0 << endl;
        return 0;
    }

    
    while (k) {
        // cout << endl;
        string bestAttr = "";
        ll bestAttrIncr = -1, currAttrIncr;
        for (auto x: attrs) {
            currAttrIncr = 0;
            attrName = x.first;
            attrScore = x.second;

            if (!IN(attrName, treshs)) {
                continue;
            }

            if (attrScore == treshs[attrName]) {
                currAttrIncr += attrScore;
            }

            currAttrIncr += reqs[attrName].size();

            // cout << attrName << " " << attrScore << " " << treshs[attrName] << " " << currAttrIncr << " reqs: ";
            // for (auto y: reqs[attrName]) cout << y << " ";
            // cout << endl;

            if (currAttrIncr > bestAttrIncr) {
                bestAttrIncr = currAttrIncr;
                bestAttr = attrName;
            }
        }

        k--;
        attrs[bestAttr]++;
    }

    // cout << endl;
    ll ans = 0ll;
    for (auto x: reqs) {
        attrName = x.first;
        // cout << attrName << " " << attrs[attrName] << endl;

        ans += attrs[attrName]*(reqs[attrName].size());
        if (attrs[attrName] == treshs[attrName]) {
            ans -= attrs[attrName];
        }
    }

    cout << ans << endl;

	return 0;
}