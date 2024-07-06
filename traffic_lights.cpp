#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    
    multiset<int> streets;
    multiset<int> gaps;
    
    // Insert initial boundary points
    streets.insert(0);
    streets.insert(x);
    gaps.insert(x); // Initially, the gap is the whole street length
    
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        
        auto it = streets.lower_bound(t);
        int right = *it;
        int left = *(--it);
        
        // Remove the current gap
        gaps.erase(gaps.find(right - left));
        
        // Insert new gaps
        gaps.insert(t - left);
        gaps.insert(right - t);
        
        // Insert the new traffic light position
        streets.insert(t);
        
        // Output the current maximum gap
        cout << *gaps.rbegin() << " ";
    }
    
    return 0;
}
