#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

ll mod = 1000000007;

int scores[] = {100,75,60,50,45,40,36,32,29,26,24,22,20,18,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> contestants(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            cin >> contestants[i][j];
        }
        sort(contestants[i].begin()+1, contestants[i].end(), greater<int>());
        contestants[i][0] = accumulate(contestants[i].begin()+1, min(contestants[i].begin()+5, contestants[i].end()), 0);
    }

    // // prints out all of contestants double array
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << contestants[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int my_score = contestants[0][0];
    int my_rank = 1;

    vector<int> missings;
    for (int i = 1; i < m; i++) {
        if (contestants[i][0] > my_score) my_rank++;
        else missings.push_back(my_score - accumulate(contestants[i].begin()+1, min(contestants[i].begin()+4, contestants[i].end()), 0) + 1);
    }
    sort(missings.begin(), missings.end());

    // for (auto x : missings) cout << x << " ";
    // cout << endl;

    int low = 0, high = missings.size() + 1;
    while (high - low > 1) {
        int mid = low + (high - low) / 2;
        // cout << "mid= " << mid << endl;
        int missing = missings[0];
        int tot = 0, group = 0;

        // cout << mid << " " << low << " " << high << " " << missing << " " << tot << " " << group << endl;
        for (int i = 0; i < mid; i++) {
            // cout << mid << " " << low << " " << high << " " << missing << " " << tot << " " << group << endl;
            group++;

            if (mid - i <= 30) {
                tot += scores[mid-i-1];
            }
            tot += 1;

            missing = missings[i];
            if (tot + group - 1 >= group * missing) {
                tot = 0;
                group = 0;
            }
        }

        if (group == 0) {
            low = mid;
        } else {
            high = mid;
        }
        // cout << mid << " " << low << " " << high << " " << missing << " " << tot << " " << group << endl;
    }

    cout << my_rank + low << endl;    

    return 0;
}