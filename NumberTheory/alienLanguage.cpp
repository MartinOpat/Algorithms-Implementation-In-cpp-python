#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back

ll mod = 1000000007;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;

    string num, source, goal;
    int case_num = 1;
    while (t--) {
        cin >> num >> source >> goal;

        map<char, int> indeces;
        int i = 0;
        for (char c: source) {
            indeces[c] = i;
            i++;
        }

        ll decimal = 0ll;
        ll base = source.length();
        ll step_base = 1;
        for (int j = num.length()-1; j >= 0; j--) {
            decimal += indeces[num[j]]*step_base;
            step_base *= base;
        }

        base = goal.length();
        string ans = "";

        while (decimal) {
            ans += goal[decimal % base];
            decimal /= base;
        }

        reverse(ans.begin(), ans.end());
        cout << "Case #" << case_num++ << ": " << ans << endl;
    }

    return 0;
}