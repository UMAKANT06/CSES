#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> task(n);

    for (int i = 0; i < n; i++) {
        long long f, s;
        cin >> f >> s;
        task[i].first = f;
        task[i].second = s;
    }

    sort(task.begin(), task.end());

    long long s = 0;
    vector<long long> f(n);
    for (int i = 0; i < n; i++) {
        s += task[i].first;
        f[i] = s;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (task[i].second - f[i]);
    }

    cout << ans << " ";
    return 0;
}
