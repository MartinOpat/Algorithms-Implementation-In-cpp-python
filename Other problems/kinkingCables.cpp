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

    int n, m;
    cin >> n >> m;

    double l;
    cin >> l;

    int k = 1;
    vector<pair<double, double>> points = {{0, 0}};
    int x=0, y=0;

    if (abs(m*m + n*n - l*l) < 1e-7) {
        k++;
        points.psh({n, m});

        cout << k << endl;
        for (auto x: points) {
            cout << x.first << " " << x.second << endl;
        }
        return 0;
    }

    while (l - (n+1) > m-(y+1) + x) {
        k += 2;
        points.psh({n-x, y});
        points.psh({n-x, y+1});
        y++;
        x = n-x;
        l -= n+1;
    }

    // if (l - (m - y + n - x) > 1e-7)
    
    
    if (x) {
        double dx = (l+y-m)/2;
        k += 3;
        points.psh({n-dx, y});
        points.psh({n-dx, y+1});
        points.psh({n, y+1});

    } else {
        double dx = (m-y+n-x-l)/2;
        points[points.size()-1] = {dx, points[points.size()-1].second};
        if (points.size() > 1) {
            points[points.size()-2] = {dx, points[points.size()-2].second};
        }

        k++;
        points.psh({n, y});
    }


    k++;
    points.psh({n, m});

    cout << k << endl;
    for (auto x: points) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}