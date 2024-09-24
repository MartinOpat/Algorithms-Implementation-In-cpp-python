#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    map<int, set<string>> items;
    for (int i = 0; i < k; i++) {
        int key;
        string value;
        cin >> key >> value;
        items[key].insert(value);
    }

    int m;
    cin >> m;
    vector<string> l(m);
    for (auto &x: l) cin >> x;


    vector<int> path, path2;
    int i_need=0, i_shop=0;

    while (i_need < m and i_shop < n) {
        if (items[i_shop].find(l[i_need]) != items[i_shop].end()) {
            i_need += 1;
            path.push_back(i_shop);
        } else {
            i_shop += 1;
        }
    }

    if (i_need != m) {
        cout << "impossible" << endl;
        return 0;
    }

    i_need = m-1;
    i_shop = n-1;
    while (i_need >= 0 and i_shop >= 0) {
        if (items[i_shop].find(l[i_need]) != items[i_shop].end()) {
            i_need -= 1;
            path2.push_back(i_shop);
        } else {
            i_shop -= 1;
        }
    }

    if (path.size() != path2.size()) {
        cout << "ambiguous" << endl;
        return 0;
    }

    for (int i=0; i<path.size(); i++){
        if (path[i] != path2[path.size()-1-i]) {
            cout << "ambiguous" << endl;
            return 0;
        }
    }

    cout << "unique" << endl;
    return 0;
}