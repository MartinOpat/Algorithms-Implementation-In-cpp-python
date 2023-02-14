#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define psh push_back


template <typename T>
class DisjointSet {
    typedef T * iterator;
    T *parent, n, *rank;
    public:
        // O(n), assumes nodes are [0, n)
        DisjointSet(T n) {
            this->parent = new T[n];
            this->n = n;
            this->rank = new T[n];

            for (T i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        // O(log n)
        T find_set(T x) {
            if (x == parent[x]) {
                return x;
            }
            return parent[x] = find_set(parent[x]);
        }

        // O(log n)
        void union_sets(T x, T y) {
            x = this->find_set(x);
            y = this->find_set(y);

            if (x == y) return;

            if (rank[x] < rank[y]) {
                T z = x;
                x = y;
                y = z;
            }

            parent[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
};

// O(E log E)
pair<set<pair<ll, ll>>, ll>  kruskal(vector<tuple<ll, ll, ll>>& edges, ll n) {
    set<pair<ll, ll>> ans;
    ll cost = 0;

    sort(edges.begin(), edges.end());
    DisjointSet<ll> fs(n);

    ll dist, i, j;
    for (auto edge: edges) {
        dist = get<0>(edge);
        i = get<1>(edge);
        j = get<2>(edge);

        if (fs.find_set(i) != fs.find_set(j)) {
            fs.union_sets(i, j);
            ans.insert({i, j});
            cost += dist;
        }
    }

    return pair<set<pair<ll, ll>>, ll> {ans, cost};
}


/////////////////////////////////////////////////////////////
// Usage example

ll get_distance(string a, string b, ll k) {
    ll count = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] != b[i]) {
            count++;
        }
    }
    return count;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    vector<string> dnas;
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        dnas.psh(temp);
    }

    vector<tuple<ll, ll, ll>> edges;
    ll dist;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            edges.psh({get_distance(dnas[i], dnas[j], k), i, j});
        }
    }

    auto ansPair = kruskal(edges, n);
    auto ans = ansPair.first;
    ll unlike = ansPair.second;
    cout << unlike << endl;
    for (auto x: ans) cout << x.first << " " << x.second << endl;
    

    return 0;
}