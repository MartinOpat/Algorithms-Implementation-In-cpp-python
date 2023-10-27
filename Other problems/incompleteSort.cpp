#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define IN(el, arr) (arr.find((el)) != arr.end())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> a;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back({temp, i});
	}

	auto b = a;
	sort(b.begin(), b.end());

	cout << 3 << endl;

	set<int> print_ind;
	vector<int> print_a;
	for (int i = 0; i < n / 4; i++) {
		if (!IN(a[i].second, print_ind)) {
			print_ind.insert(a[i].second);
			print_a.push_back(a[i].first);
		}
		if (!IN(b[i].second, print_ind)) {
			print_ind.insert(b[i].second);
			print_a.push_back(b[i].first);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (print_ind.size() == n / 2) {
			break;
		}

		if (!IN(i, print_ind)) {
			print_ind.insert(i);
			print_a.push_back(a[i].first);
		}
	}
	sort(print_a.begin(), print_a.end());
    int i_ = 0;
	for (auto it = print_ind.begin(); it != print_ind.end(); it = next(it)) {
		cout << *it + 1;
		if (next(it) != print_ind.end()) {
			cout << " ";
		} else {
			cout << endl;
		}
        a[*it] = {print_a[i_], *it};
        i_++;
	}
    b = a;
    sort(b.begin(), b.end());

	print_ind = {};
	for (int i = n / 4; i < n / 2; i++) {
		if (!IN(a[i].second, print_ind)) {
			print_ind.insert(a[i].second);
		}
		if (!IN(b[i].second, print_ind)) {
			print_ind.insert(b[i].second);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (print_ind.size() == n / 2) {
			break;
		}

		if (!IN(i, print_ind)) {
			print_ind.insert(i);
		}
	}
	for (auto it = print_ind.begin(); it != print_ind.end(); it = next(it)) {
		cout << *it + 1;
		if (next(it) != print_ind.end()) {
			cout << " ";
		} else {
			cout << endl;
		}
	}

	for (int i = n / 2; i < n; i++) {
		cout << i + 1;
		if (i != n - 1) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
}
