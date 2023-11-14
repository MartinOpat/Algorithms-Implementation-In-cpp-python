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

// int main() {
// 	ios::sync_with_stdio(false);  // do not use cout + printf
// 	cin.tie(NULL);
//  cout << fixed << setprecision(12);
// 	return 0;
// }