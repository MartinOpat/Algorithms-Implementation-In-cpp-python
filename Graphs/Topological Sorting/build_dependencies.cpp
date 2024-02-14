#include <bits/stdc++.h>
using namespace std;

void dfs(map<string, vector<string>>& adj, string key, stack<string>& stk, unordered_set<string>& visited) {
    visited.insert(key);
    for (const string& value : adj[key]) {
        if (visited.find(value) == visited.end()) {
            dfs(adj, value, stk, visited);
        }
    }
    stk.push(key);
    
}

vector<string> get_dependencies(map<string, vector<string>>& adj, string changed) {
    // Perform topological sort
    stack<string> stk;
    unordered_set<string> visited;
    dfs(adj, changed, stk, visited);

    // Print the values in topological order
    vector<string> result;
    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }
    return result;
}


int main() {
    int n;
    string nStr;
    getline(cin, nStr);
    n = stoi(nStr);

    map<string, vector<string>> adj;

    string changed;
    while (n--) {
        string line;
        getline(cin, line);

        size_t pos = line.find(":");
        string value = line.substr(0, pos);
        string keys = line.substr(pos + 1);
        // cout << value << "-" << keys << endl;   
        if (!keys.empty()) {
            keys = keys.substr(1);
        }
        
        stringstream ss(keys);
        string key;
        while (ss >> key) {
            if (adj.find(key) == adj.end()) {
                adj[key] = vector<string>{value};
            } else {
                adj[key].push_back(value);
            }
        }
    }
    getline(cin, changed);

    for (string element : get_dependencies(adj, changed)) {
        cout << element << endl;
    }
    
    
    return 0;
}
