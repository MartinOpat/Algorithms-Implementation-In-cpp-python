#include<bits/stdc++.h>

using namespace std;
using ld = long double;

ld log_factorial(int n) {
    ld sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += logl((ld)i);
    }
    return sum;
}

ld log_stirling(int num) {
    ld n = (ld) num;
    return (0.5 * logl(2 * M_PI * n)) + n * (logl(n) - 1);
}

ld compute_ans(int n) {
    if (n == 0) return 1;
    return expl(-log_stirling(n) + log_factorial(n));
}

int main() {
    int n;
    cin >> n;

    cout << setprecision(9) << fixed;
    while (n != 0) {
        cout << compute_ans(n) << endl;
        cin >> n;
    }

    return 0;
}