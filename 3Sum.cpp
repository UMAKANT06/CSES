#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[i] = {k, i}; // Store value and original index
    }

    // Sort based on the values
    sort(a.begin(), a.end());

    for (int i = 0; i < n - 2; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int sum = a[i].first + a[l].first + a[r].first;
            if (sum == x) {
                // Print original indices (1-based index)
                cout << a[i].second + 1 << " " << a[l].second + 1 << " " << a[r].second + 1 << endl;
                return 0;
            } else if (sum < x) {
                l++;
            } else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
