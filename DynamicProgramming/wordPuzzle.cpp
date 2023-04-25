#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

const ll mod = 1000000007LL;
vector<vector<ll>> dp;


ll f(ll i, ll j, string p, string s) {
    if (j >= s.size()) return 1;
    if (i >= p.size()) return 0;
    if (s.size() - j > p.size() - i) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (p[i] == s[j]) {
        ll c1 = f(i+1, j+1, p, s) % mod;
        ll c2 = f(i+1, j, p, s) % mod;
        dp[i][j] = (c1 + c2) % mod;
        return dp[i][j];
    }

    dp[i][j] = f(i+1, j, p, s) % mod;
    return dp[i][j];
}




int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string p, s;
    cin >> p >> s;
    string sOrig(s);

    ll ans = 0;
    // set<string> tried;

    for (int i = 0; i < p.size(); i++) {
        vector<ll> temp(s.size(), -1);
        dp.psh(temp);
    }
    
    
    for (int i = 0; i < s.size(); i++) {
        // if (tried.find(s) != tried.end()) {
        //     continue;
        // }
        // tried.insert(s);

        if (i != 0 && s.compare(sOrig) == 0) {
            break;
        }
        
        for (int j = 0; j < p.size(); j++) {
            for (int k = 0; k < s.size(); k++) {
                dp[j][k] = -1;
            }
        }
        
        ans += f(0, 0, p, s) % mod;
        rotate(s.begin(), s.end()-1, s.end());
    }

    cout << ans % mod << endl;

    return 0;
}