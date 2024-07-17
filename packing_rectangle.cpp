#include <bits/stdc++.h>
using namespace std;

bool canFit(long long x, long long  w, long long h, long long n) {
    return (x / w) * (x / h) >= n;
}

int main() {
    long long  w, h, n;
    cin >> w >> h >> n;

    long long l = 0;
    long long r = 1LL * max(w, h) * n;

    while (l < r) {
        long long m = l + (r - l) / 2;
        if (canFit(m, w, h, n)) {
            r = m; // Try to find a smaller square
        } else {
            l = m + 1; // Increase the size of the square
        }
    }

    cout << l << endl;
    return 0;
}
