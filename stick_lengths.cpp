#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> p(n); // Change the type of the vector to long long
    
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    sort(p.begin(), p.end());
    long long median = p[n / 2]; // Change the type of median to long long
    
    long long min_x = 0; // Change the type of min_x to long long
    for(int i = 0; i < n; i++) {
        min_x += abs(p[i] - median);
    }
    
    cout << min_x << " ";
    return 0;
}
