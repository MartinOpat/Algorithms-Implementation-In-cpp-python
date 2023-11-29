#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpl vector<pl>
#define vpi vector<pi>
#define vld vector<ld>
#define in(el, cont) (cont.find(el) != cont.end())

constexpr int INF  = 2000000010;
constexpr ll LLINF = 9000000000000000010LL;

template <typename T, template <typename ELEM, typename ALLOC = std::allocator<ELEM> > class Container>
std::ostream& operator<<(std::ostream& o, const Container<T>& container) {
	typename Container<T>::const_iterator beg = container.begin();
	if (beg != container.end()) {
		o << *beg++;
		while (beg != container.end()) {
			o << " " << *beg++;
		}
	}
	return o;
}

template<class T>
vector<T> pathOfLIS(vector<T>& nums) {
	int n = nums.size();
	vector<T> sub; 
		vector<int> subIndex;
	vector<T> path(n, -1); 
	for (int i = 0; i < n; ++i) {
	    if (sub.empty() || sub[sub.size() - 1] < nums[i]) {
		path[i] = sub.empty() ? -1 : subIndex[sub.size() - 1];
		sub.push_back(nums[i]);
		subIndex.push_back(i);
	    } else {
		int idx = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
		path[i] = idx == 0 ? -1 : subIndex[idx - 1];
		sub[idx] = nums[i];
		subIndex[idx] = i;
	    }
	}
	vector<T> ans;
	int t = subIndex[subIndex.size() - 1];
	while (t != -1) {
	    ans.push_back(t);
	    t = path[t];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	ios::sync_with_stdio(false);  // do not use cout + printf
	cin.tie(NULL);
    // cout << fixed << setprecision(12);

    int n;
    while(cin >> n) {
        vector<ll> xs(n);
        for (auto& x: xs) cin >> x;

        vector<ll> ans = pathOfLIS(xs);
        cout << ans.size() << endl;
		cout << ans << endl;
    }

	return 0;
}
