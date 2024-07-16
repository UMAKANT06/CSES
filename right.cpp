#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(k);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int j = 0; j < k; j++) {
        cin >> b[j];
    }

    sort(a.begin(), a.end()); // Ensure the array is sorted for binary search

    for (int j = 0; j < k; j++) {
        int g = b[j];
        // Use lower_bound to find the first element greater than g
        auto it = lower_bound(a.begin(), a.end(), g);

        if (it == a.end()) {
            // No element in array a is less than or equal to g
            cout <<n+1<< endl;
        } else {
            // Get the maximum index of element not greater than g
            int idx = it - a.begin();
            cout << idx + 1 << endl; // 1-based index
        }
    }

    return 0;
}
