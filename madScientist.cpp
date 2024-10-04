#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        // When characters don't match
        if (a[i] != b[i]) {
            count++;
            // Skip over consecutive mismatches
            while (i < n && a[i] != b[i]) {
                i++;
            }
            // Decrement i to prevent over-skipping in the next iteration
            i--;
        }
    }
    
    cout << count << endl;
    return 0;
}
