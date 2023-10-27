#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> cs;
	int temp_a, temp_c;
	for (int i = 0; i < m; i++) {
		cin >> temp_c >> temp_a;
		cs.push_back({temp_c, temp_a});
	}

    vector<int> lines(n ,0);
	for (int i = 0; i < n; i++) {
		cin >> lines[i];
	}

    
}