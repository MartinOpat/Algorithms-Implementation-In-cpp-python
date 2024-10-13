// // longest palindrome substring

// #include <bits/stdc++.h>

// using namespace std;

// #define vi vector<int>

// int main() {
//     string s;
//     cin >> s;

//     int n = s.size();

//     // Longest even length palindrome
//     int start = 0, len = 0;
//     for (int i = 0; i < n; i++) {
//         int l = i, r = i + 1;
//         while (l >= 0 && r < n && s[l] == s[r]) {
//             if (r - l + 1 > len) {
//                 start = l;
//                 len = r - l + 1;
//             }
//             l--;
//             r++;
//         }
//     }

//     // Longest odd length palindrome
//     for (int i = 0; i < n; i++) {
//         int l = i, r = i;
//         while (l >= 0 && r < n && s[l] == s[r]) {
//             if (r - l + 1 > len) {
//                 start = l;
//                 len = r - l + 1;
//             }
//             l--;
//             r++;
//         }
//     }

//     cout << s.substr(start, len) << endl;
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return "";

    // Transform the string to handle even and odd length palindromes uniformly
    string t = "#";
    for (int i = 0; i < n; i++) {
        t += s[i];
        t += "#";
    }

    int m = t.size();
    vector<int> p(m, 0);
    int c = 0, r = 0; // current center and right edge of the palindrome

    for (int i = 0; i < m; i++) {
        int mirr = 2 * c - i; // mirror of i with respect to center c

        if (i < r) {
            p[i] = min(r - i, p[mirr]);
        }

        // Expand around the center
        while (i + p[i] + 1 < m && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }

        // Update the center and right edge
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }

    // Find the maximum length palindrome
    int maxLen = 0, centerIndex = 0;
    for (int i = 0; i < m; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    // Extract the longest palindromic substring
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}