#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the weights of the children
    sort(a.begin(), a.end());

    int left = 0;
    int right = n - 1;
    int gondolas = 0;

    while (left <= right) {
        if (a[left] + a[right] <= x) {
            // If the lightest and the heaviest child can share a gondola
            left++;
            right--;
        } else {
            // Only the heaviest child gets their own gondola
            right--;
        }
        gondolas++;
    }

    cout << gondolas << endl;
    return 0;
}
