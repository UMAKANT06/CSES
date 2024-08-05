#include <iostream>
#include <algorithm>

using namespace std;

bool canMakeCopies(long long mid, int n, int x, int y) {
    // Calculate copies made by each copier in 'mid' seconds
    long long copiesByX = mid / x;
    long long copiesByY = mid / y;
    
    // Total copies made
    return (copiesByX + copiesByY) >= n;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    
    // Ensure x <= y for simplifying calculations
    if (x > y) {
        swap(x, y);
    }
    n=n-1;
    
    // Binary search for the minimum time
    long long low = 0;
    long long high = static_cast<long long>(n) * x;
    long long result = high;
    
    while (low <= high) {
        long long mid = (low + high) / 2;
        
        if (canMakeCopies(mid, n, x, y)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    // Print the minimum time required
    cout << result+min(x,y)<< endl;
    
    return 0;
}
