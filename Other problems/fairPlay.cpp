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

	int n;
	cin >> n;

    if (n%2) {
        cout << "impossible" << endl;
        return 0;
    }

	vector<pair<ll, ll>> skills(n, {0, 0});
	for (int i = 0; i < n; i++) {
		cin >> skills[i].first >> skills[i].second;
	}

    ll sum_b = 0, sum_p = 0;
    for (auto x: skills) {
        sum_b += x.first;
        sum_p += x.second;
    }

    ll double_av_b = 2*sum_b / n;
    ll double_av_p = 2*sum_p / n;
    bool is_int_av_b = (2*sum_b) % n == 0;
    bool is_int_av_p = (2*sum_p) % n == 0;

    // cout << double_av_b << " " << is_int_av_b << ", " << double_av_p << " " << is_int_av_p << endl;

    if (!is_int_av_b || !is_int_av_p) {
        cout << "impossible" << endl;
        return 0;
    }

    map<pair<ll, ll>, int> req;
    for (auto x: skills) {
        pair<ll, ll> s = {double_av_b - x.first, double_av_p - x.second};

        if (IN(x, req)) {
            if (req[x] > 1) {
                req[x]--;
            } else{
                req.erase(x);
            }
        } else {
            if (IN(s, req)) {
                req[s]++;
            } else {
                req.insert({s, 1});
            }
        }
    }

    // for (auto x: req) {
    //     cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    // }

    if (req.empty()) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }



	return 0;
}