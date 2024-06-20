#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, k;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int length = 0, s = 0;
    int l = 0, r = 0;

    while (r < n) {
        s += a[r];
        while (s > t) {
            s -= a[l];
            l++;
        }
        length = max(length, r - l + 1);
        r++;
    }

    cout << length << endl;
    return 0;
}
