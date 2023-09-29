#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

ll mod = 1000000007;
int table[] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int s, p, f, o;
	vector<vector<int>> scores;
	for (int i = 0; i < n; i++) {
		cin >> s >> p >> f >> o;
		scores.push_back(vector<int>{s, -p, -f, o, i});
	}

	sort(scores.rbegin(), scores.rend());

	// cout << "Sorted stuff:" << endl;
	// for (int i = 0; i < n; i++) {
	// 	for (auto x: scores[i]) cout << x << " ";
	//     cout << endl;
	// }

	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++) {
		// ans[scores[i][4]] = scores[i][3] + (i < 30 ? table[i] : 0);
        int j = i+1;
        while (i+j < n) {
            if (scores[i][0] == scores[j][0] && scores[i][1] == scores[j][1] && scores[i][2] == scores[j][2]) {
                j++;
            } else {
                break;
            }
        }
        
        int num_sharing = j - i;
        int score = 0;
        for (int k = 0; k < num_sharing; k++) {
            score += (i+k < 30 ? table[i+k] : 0);
        }
        score = (score + num_sharing - 1) / num_sharing;

        for (int k = 0; k < num_sharing; k++) {
            ans[scores[i + k][4]] = score + scores[i+k][3];
        }

        i += num_sharing-1;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
    cout << endl;

	return 0;
}