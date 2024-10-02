#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> customers;  // {arrival, departure, index}
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        customers.push_back({a, b, i});
    }

    // Sort customers by arrival time
    sort(customers.begin(), customers.end());

    priority_queue<pi, vector<pi>, greater<pi>> pq;  // Min-heap {departure time, room number}
    vector<int> room_assignment(n);
    int room_count = 0;

    for (auto [arrival, departure, idx] : customers) {
        if (!pq.empty() && pq.top().first < arrival) {
            // Reuse the earliest available room
            auto [earliest_departure, room] = pq.top();
            pq.pop();
            room_assignment[idx] = room;
        } else {
            // Assign a new room
            room_count++;
            room_assignment[idx] = room_count;
        }
        // Add the current customer's room with their departure time
        pq.push({departure, room_assignment[idx]});
    }

    // Output the number of rooms
    cout << room_count << endl;
    // Output the room assignments in the order of customers
    for (int i = 0; i < n; i++) {
        cout << room_assignment[i] << " ";
    }
    cout << endl;

    return 0;
}
