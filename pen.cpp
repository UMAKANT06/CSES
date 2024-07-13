#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, g, b;
    string c;
    cin >> r >> g >> b;
    cin >> c;

    if (c == "Red") {
        cout << min(g, b) << " ";
    } else if (c == "Blue") {
        cout << min(r, g) << " ";
    } else if (c == "Green") {
        cout << min(r, b) << " ";
    } else {
        cout << "Invalid color" << " ";
    }
    
    return 0;
}
