#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

// Declare the DP array and the Trie data structure
vector<int> dp(5005);


const int ALPHABET_SIZE = 26;
inline int mp(char c) { return c - 'a'; }
struct Node {
	Node* ch[ALPHABET_SIZE];
	bool isleaf = false;
	Node() {
		for(int i = 0; i < ALPHABET_SIZE; ++i) ch[i] = nullptr;
	}

	void insert(string &s, int i = 0) {
		if (i == s.length()) isleaf = true;
		else {
			int v = mp(s[i]);
			if (ch[v] == nullptr)
				ch[v] = new Node();
			ch[v]->insert(s, i + 1);
		}
	}

	bool contains(string &s, int i = 0) {
		if (i == s.length()) return isleaf;
		else {
			int v = mp(s[i]);
			if (ch[v] == nullptr) return false;
			else return ch[v]->contains(s, i + 1);
		}
	}

	void cleanup() {
		for (int i = 0; i < ALPHABET_SIZE; ++i)
			if (ch[i] != nullptr) {
				ch[i]->cleanup();
				delete ch[i];
			}
	}
};

Node root;

int countWays(int start, string& S)
{
    Node* currentNode = &root;
    int ways = 0;
    for (int i = start; i < S.size(); i++) {
        int index = mp(S[i]);
        if (currentNode->ch[index] == nullptr)
            return ways;
        currentNode = currentNode->ch[index];
        // If a word ends here, add the number of ways from the next index
        if (currentNode->isleaf)
            ways = (ways + dp[i + 1]) % mod; 
    }
    return ways;
}

void solve(string& S, int K, string word[])
{
    for (int i = 0; i < K; i++) {
        // Insert each word into the Trie
        root.insert(word[i]); 
    }
    // Base case: One way to form an empty string
    dp.resize(S.size() + 1);
    dp[S.size()] = 1; 
    for (int i = S.size() - 1; i >= 0; i--) {
        // Fill the DP table from right to left
        dp[i] = countWays(i, S);
    }
    // The answer is the number of ways to form the string from index 0
    cout << dp[0]; 
}
// Driver Code
int main()
{
    // Input from user
    string S;
    cin >> S;
    int K;
    cin >> K;
    string arr[K];
    for (int i = 0; i < K; i++)
        cin >> arr[i];


    
    solve(S, K, arr);
    return 0;
}
