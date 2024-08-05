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
    long long result = r;
    while (l <= r) {
        long long m = l + r / 2;
        if (canFit(m, w, h, n)) {
            r = m-1; // Try to find a smaller square
        } else {
            result=l;
            l = m + 1; // Increase the size of the square
        }
    }

    cout << result << endl;
    return 0;
}
