#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll MOD = 1000000007;
unordered_map<ll, ll> Fib;

ll fib(ll n) {
	if (n < 2) return 1;
	if (Fib.find(n) != Fib.end()) return Fib[n];
	Fib[n] = (fib((n + 1) / 2) * fib(n / 2) + fib((n - 1) / 2) * fib((n - 2) / 2)) % MOD;
	return Fib[n];
}

int main() {
	ll N;
	cin >> N;
	if (N < 0) return 0;
	if (N == 1 || N == 2)
		cout << N << endl;
	else
		cout << fib(N + 1) - 1 << endl;
}