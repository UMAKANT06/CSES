#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, k;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> k;
        a[i] = {k, i}; // Store value and original index
    }

    // Sort based on the values
    sort(a.begin(), a.end());

    int l = 0, r = n - 1;
    while (l < r) {
        int sum = a[l].first + a[r].first;
        if (sum == x) {
            // Print original indices (1-based index)
            cout << a[l].second + 1 << " " << a[r].second + 1 << endl;
            return 0;
        } else if (sum > x) {
            r--;
        } else {
            l++;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
