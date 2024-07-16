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
        int l = 0, r = a.size() - 1;
        bool found = false;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (a[m] == g) {
                found = true;
                break;
            } else if (a[m] < g) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
