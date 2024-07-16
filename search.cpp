#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    cin>>k;
    vector<pair<int, int>> b(k);
    
    for (int j = 0; j < k; j++) {
        cin >> b[j].first >> b[j].second;
    }
    
    for (int j = 0; j < k; j++) {
        int f = b[j].first;
        int s = b[j].second;
        auto it1 = lower_bound(a.begin(), a.end(), f);
        auto it2 = upper_bound(a.begin(), a.end(), s);
        
        if (it1 == a.end() || it1 >= it2) {
            cout << 0 << endl;
        } else {
            int idxl = it1 - a.begin();
            int idxr = it2 - a.begin();
            cout << (idxr - idxl) << endl;
        }
    }
    
    return 0;
}
