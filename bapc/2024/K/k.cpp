#include <bits/stdc++.h>

template <class T>
size_t hash_combine(size_t seed, const T &v) {
	return seed ^ (std::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2));
}
namespace std {
template <typename U, typename V>
struct hash<pair<U, V>> {
	size_t operator()(const pair<U, V> &k) const {
		return hash_combine(hash_combine(0, k.first), k.second);
	}
};
}

using namespace std;
using ull = unsigned long long;
const ull mod1 = 1e9 + 7, mod2 = 1e9 + 9, base1 = 911, base2 = 1597;

int main() {
	string s;
	getline(cin, s);
	int n = s.size(), min_total = n + 1;
	vector<ull> h1(n + 1), h2(n + 1), p1(n + 1, 1), p2(n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		h1[i] = (h1[i - 1] * base1 + s[i - 1]) % mod1;
		h2[i] = (h2[i - 1] * base2 + s[i - 1]) % mod2;
		p1[i] = (p1[i - 1] * base1) % mod1;
		p2[i] = (p2[i - 1] * base2) % mod2;
	}
	for (int L = 1; L <= n; ++L) {
		unordered_map<pair<ull, ull>, vector<int>> m;
		for (int i = 0; i <= n - L; ++i) {
			ull hash1 = (h1[i + L] + mod1 - (h1[i] * p1[L]) % mod1) % mod1;
			ull hash2 = (h2[i + L] + mod2 - (h2[i] * p2[L]) % mod2) % mod2;
			m[{hash1, hash2}].push_back(i);
		}
		for (auto &entry : m) {
			auto &positions = entry.second;
			if (positions.size() <= 1) continue;
			string t = s.substr(positions[0], L);
			bool valid = true;
			for (int idx = 1; idx < positions.size(); ++idx) {
				if (s.compare(positions[idx], L, t) != 0) {
					valid = false;
					break;
				}
			}
			if (!valid) continue;
			int k = 0, last = -L;
			for (int pos : positions) {
				if (pos >= last + L) {
					++k;
					last = pos;
				}
			}
			if (k <= 1) continue;
			int total_len = L + n - k * (L - 1);
			if (total_len < min_total) min_total = total_len;
		}
	}
	cout << min_total << endl;
	return 0;
}
