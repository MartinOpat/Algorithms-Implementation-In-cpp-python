#include <bits/stdc++.h>
using namespace std;

#define ld long double

/*
0 	1 	            +1.000000000
1 	±1/2 	        ±0.500000000 (use +)
2 	1/6 	        +0.166666666
3 	0 	            +0.000000000
4 	−1/30 	        −0.033333333
5 	0 	            +0.000000000
6 	1/42 	        +0.023809523
7 	0 	            +0.000000000
8 	−1/30 	        −0.033333333
9 	0 	            +0.000000000
10 	5/66 	        +0.075757575
11 	0 	            +0.000000000
12 	−691/2730 	    −0.253113553
13 	0 	            +0.000000000
14 	7/6 	        +1.166666666
15 	0 	            +0.000000000
16 	−3617/510 	    −7.092156862
17 	0 	            +0.000000000
18 	43867/798 	    +54.97117794
19 	0 	            +0.000000000
20 	−174611/330 	−529.1242424
*/

const ld Bernoulli[21] = {
    1, 1.0/2, 1.0/6, 0, -1.0/30, 0, 1.0/42, 0, -1.0/30, 0, 5.0/66, 0, -691.0/2730, 0, 7.0/6, 0, -3617.0/510, 0, 43867.0/798, 0, -174611/330
};

int fact[101];

void init(int a, int precision) {
    fact[0] = 1;
    for (int i = 1; i < 100 + precision + 1; i++) {
        fact[i] = fact[i-1]*i % a;
    }
}

ld fast_pow_mod(int base, int exponent, int mod) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

ld harmonic_approx(int n, int s, int precision) {
    ld ans = fact[s] - (ld) 1.0 / ((s-1) * fast_pow_mod(n, s-1, n)) + (ld) 1.0/(2*fast_pow_mod(n, s, n));

    for (int i = 1; i < precision; i++) {
        ans -= (ld) Bernoulli[2*i] / fact[2*i] * ((ld)fact[s+2*i-2] / fact[s-1] - (ld) fact[s + 2*i -2] / (fact[s-1] * fast_pow_mod(n, s+2*i-1, n)));
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int precision = 10;
    init(a, precision);

    cout << setprecision(max(6, precision/2));
    cout << harmonic_approx(a, -b, precision)  << endl;
        
    return 0;
}