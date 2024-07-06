#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> cities;
    multiset<int> towers;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        cities.insert(k);
    }

    for (int j = 0; j < m; ++j) {
        int p;
        cin >> p;
        towers.insert(p);
    }

    int maxi = 0;

    for (auto city : cities) {
        auto it = towers.lower_bound(city);

        // Closest tower on the right (or equal)
        int r_u = (it != towers.end()) ? abs(city - *it) : INT_MAX;

        // Closest tower on the left
        int r_l = (it != towers.begin()) ? abs(city - *(--it)) : INT_MAX;

        // Minimum distance to a tower
        int r = min(r_u, r_l);
        
        // Update maximum of minimum distances
        maxi = max(maxi, r);
    }

    cout << maxi << endl;
    return 0;
}
