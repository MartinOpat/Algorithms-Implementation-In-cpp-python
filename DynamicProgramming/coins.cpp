#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to calculate the minimum number of coins recursively with memoization
int minCoins(int x, const vector<int>& coins, vector<int>& dp) {
    // Base case: If sum is 0, no coins are needed
    if (x == 0) return 0;

    // If the result has already been computed, return it
    if (dp[x] != -1) return dp[x];

    int result = INT_MAX; // Initialize result to a large value

    // Try each coin and recursively calculate the minimum coins needed
    for (int coin : coins) {
        if (x - coin >= 0) {
            int subResult = minCoins(x - coin, coins, dp);
            if (subResult != INT_MAX) {
                result = min(result, subResult + 1);
            }
        }
    }

    // Store the result in dp array and return
    dp[x] = result;
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x; // Input the number of coins and the target sum

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i]; // Input the coin denominations
    }

    // Initialize the memoization table with -1 (indicating uncomputed values)
    vector<int> dp(x + 1, -1);

    // Call the recursive function to find the minimum number of coins
    int result = minCoins(x, coins, dp);

    // If result is still INT_MAX, it means it's impossible to form the sum
    if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
