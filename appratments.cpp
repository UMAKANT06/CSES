#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<pair<int, int>> ranges(n);
    for (int i = 0; i < n; i++) {
        ranges[i] = {a[i] - k, a[i] + k};
    }

    int count = 0;
    int j = 0;

    // Iterate over each element in b
    for (int i = 0; i < m; i++) {
        while (j < n && b[i] > ranges[j].second) {
            j++;
        }
        if (j < n && b[i] >= ranges[j].first && b[i] <= ranges[j].second) {
            count++;
            j++; // Move to the next range
        }
    }

    cout << count <<" ";

    return 0;
}
