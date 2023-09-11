#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define psh push_back
#define maxn 200010

int t,n,m,tree[maxn],p[maxn];

void update(int k, int z) {
    while (k <= maxn) {
        tree[k] += z;
        k += k & (-k);
        // cout << "k: " << k << endl;
    }
}

int sum(int k) {
    int ans = 0;
    while(k) {
        ans += tree[k];
        k -= k & (-k);
    }
    return ans;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, m, r;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        memset(p, 0, sizeof(p));
        memset(tree, 0, sizeof(tree));

        for (int i = 1; i <= n; i++) {
            p[i] = n - i + 1;
            update(i, 1);
        }
        int pos, s=n;
        while (m--) {
            // print all elements of the p array
            for (int i = 0; i < 100; i++) cout << p[i] << " ";
            cout << endl;

            // print all elements in the tree array
            for (int i = 0; i < 100; i++) cout << tree[i] << " ";
            cout << endl;
            cout << endl;


            cin >> pos;
            cout << "pos: " << pos << endl;
            cout << "p pos: " << p[pos] << endl;
            // if (m != 0) cout << n - sum(p[pos]) << " ";
            // else cout << n - sum(p[pos]) << endl;
            update(p[pos], -1);

            // print all elements of the p array
            for (int i = 0; i < 100; i++) cout << p[i] << " ";
            cout << endl;

            // print all elements in the tree array
            for (int i = 0; i < 100; i++) cout << tree[i] << " ";
            cout << endl;
            cout << endl;

            p[pos] = ++s;
            update(p[pos], 1);


            // print all elements of the p array
            for (int i = 0; i < 100; i++) cout << p[i] << " ";
            cout << endl;

            // print all elements in the tree array
            for (int i = 0; i < 100; i++) cout << tree[i] << " ";
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        }
    }

    return 0;
}