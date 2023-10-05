#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

const ll MOD = 1000000007ll;  // 10e9+7

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> els(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> els[i];
	}

	unordered_map<int, int> hist;
	for (auto el : els) {
		if (hist.find(el) != hist.end()) {
			hist[el]++;
		} else {
			hist[el] = 1;
		}
	}

	vector<int> freqs;
	for (auto x : hist) {
		freqs.push_back(x.second);
	}

	sort(freqs.rbegin(), freqs.rend());

	// for (auto x: freqs) cout << x << " ";
    // cout << endl;

    if (n == k) {
        cout << 0 << endl;
        return 0;
    } else if (freqs.size() == 1) {
        cout << freqs[0] - k << endl;
        return 0;
    }

    int curr_count = 1;
    int ans = freqs[0];
	for (int i = 0; i < freqs.size()-1; i++) {
		if (k - curr_count*(freqs[i] - freqs[i+1]) >= 0) {
            k -= curr_count*(freqs[i] - freqs[i+1]);
            ans = freqs[i+1];
            curr_count++;
        } else {
            ans = freqs[i] - k / curr_count;
            k -= (k / curr_count) * curr_count;
            break;
        }
	}

    ans -= k / curr_count;
    cout << ans << endl;

	return 0;
}