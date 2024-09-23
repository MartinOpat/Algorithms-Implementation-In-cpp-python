#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[6];
    int h1, h2;
    for (auto &x: arr) cin >> x;
    cin >> h1 >> h2;

    do {
        if (accumulate(arr, arr+3, 0) == h1 and accumulate(arr+3, arr+6, 0) == h2) {
            sort(arr, arr+3);
            sort(arr+3, arr+6);
            
            cout << arr[2] << " " << arr[1] << " " << arr[0] << " " << arr[5] << " " << arr[4] << " " << arr[3] << endl;
            return 0;
        } else if (accumulate(arr, arr+3, 0) == h2 and accumulate(arr+3, arr+6, 0) == h1) {
            sort(arr, arr+3);
            sort(arr+3, arr+6);
            
            cout << arr[5] << " " << arr[4] << " " << arr[3] << " " << arr[2] << " " << arr[1] << " " << arr[0] << endl;
            return 0;
        }
    } while (next_permutation(arr, arr+6));

    return 0;
}