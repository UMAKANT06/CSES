#include<bits/stdc++.h>
using namespace std;

bool can(vector<long long>& a, long long mid, long long k) {
    long long current_sum = 0;
    long long subarray_count = 1;
    
    for (long long num : a) {
        if (current_sum + num > mid) {
            subarray_count++;
            current_sum = num;
            if (subarray_count > k) {
                return false;
            }
        } else {
            current_sum += num;
        }
    }
    return true;
}

int main() {
    long long n, k;
    cin >> n >> k;
    
    vector<long long> a(n);
    long long sum = 0, max_element = 0;
    
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        max_element = max(max_element, a[i]);
    }

    long long l = max_element;
    long long r = sum;
    long long result = r;

    while (l <= r) {
        long long mid = (l + r) / 2;
        if (can(a, mid, k)) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
