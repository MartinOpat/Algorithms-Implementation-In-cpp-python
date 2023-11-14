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

using C = ll;	// could be long long or long double
constexpr C EPS = 0;	// change to 0 for C=ll, change to 1e-10 for C=ld
struct P {		// may also be used as a 2D vector
	C x, y;
	P(C x = 0, C y = 0) : x(x), y(y) {}
	P operator+ (const P &p) const { return {x + p.x, y + p.y}; }
	P operator- (const P &p) const { return {x - p.x, y - p.y}; }
	P operator* (C c) const { return {x * c, y * c}; }
	P operator/ (C c) const { return {x / c, y / c}; }
	C operator* (const P &p) const { return x*p.x + y*p.y; }
	C operator^ (const P &p) const { return x*p.y - p.x*y; }
	P perp() const { return P{y, -x}; }
	C lensq() const { return x*x + y*y; }
	ld len() const { return sqrt((ld)lensq()); }
	static ld dist(const P &p1, const P &p2) {
		return (p1-p2).len(); }
	bool operator==(const P &r) const {
		return ((*this)-r).lensq() <= EPS*EPS; }
};
C det(P p1, P p2) { return p1^p2; }
C det(P p1, P p2, P o) { return det(p1-o, p2-o); }
C det(const vector<P> &ps) {
	C sum = 0; P prev = ps.back();
	for(auto &p : ps) sum += det(p, prev), prev = p;
	return sum;
}
// Careful with division by two and C=ll
C area(P p1, P p2, P p3) { return abs(det(p1, p2, p3))/C(2); }
C area(const vector<P> &poly) { return abs(det(poly))/C(2); }
int sign(C c){ return (c > C(0)) - (c < C(0)); }
int ccw(P p1, P p2, P o) { return sign(det(p1, p2, o)); }

struct ConvexHull {	 // O(n lg n) monotone chain.
	size_t n;
	vector<size_t> h, c;  // Indices of the hull are in `h`, ccw.
	const vector<P> &p;
	ConvexHull(const vector<P> &_p) : n(_p.size()), c(n), p(_p) {
		std::iota(c.begin(), c.end(), 0);
		std::sort(c.begin(), c.end(), [this](size_t l, size_t r) -> bool { return p[l].x != p[r].x ? p[l].x < p[r].x : p[l].y < p[r].y; });
		c.erase(std::unique(c.begin(), c.end(), [this](size_t l, size_t r) { return p[l] == p[r]; }), c.end());
		for (size_t s = 1, r = 0; r < 2; ++r, s = h.size()) {
			for (size_t i : c) {
				while (h.size() > s && ccw(p[h.end()[-2]], p[h.end()[-1]], p[i]) <= 0)
					h.pop_back();
				h.push_back(i);
			}
			reverse(c.begin(), c.end());
		}
		if (h.size() > 1) h.pop_back();
	}
	size_t size() const { return h.size(); }
	template <class T, void U(const P &, const P &, const P &, T &)>
	void rotating_calipers(T &ans) {
		if (size() <= 2)
			U(p[h[0]], p[h.back()], p[h.back()], ans);
		else
			for (size_t i = 0, j = 1, s = size(); i < 2 * s; ++i) {
				while (det(p[h[(i + 1) % s]] - p[h[i % s]], p[h[(j + 1) % s]] - p[h[j]]) >= 0)
					j = (j + 1) % s;
				U(p[h[i % s]], p[h[(i + 1) % s]], p[h[j]], ans);
			}
	}
};
// Example: furthest pair of points. Now set ans = 0LL and call
// ConvexHull(pts).rotating_calipers<ll, update>(ans);
void update(const P &p1, const P &p2, const P &o, ll &ans) {
	ans = max(ans, (ll)max((p1 - o).lensq(), (p2 - o).lensq()));
}

int main() {
	ios::sync_with_stdio(false);  // do not use cout + printf
	cin.tie(NULL);
	// cout << fixed << setprecision(12);

	int n;
	cin >> n;
	while (n) {
		vector<P> ps;
        int x, y;
		for (int i = 0; i < n; i++) {
            cin >> x >> y;
            ps.push_back({x, y});
        }

        ConvexHull ch(ps);
        cout << ch.h.size() << endl;
        for(auto& p: ch.h) {
            cout << ps[p].x << " " << ps[p].y << endl;
        }
		cin >> n;
	}

	return 0;
}