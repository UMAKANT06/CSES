#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    bool isRightAngle = false;

    // Check if any pair of points forms a vertical line and the third point is aligned horizontally
    if ((x2 - x1) != 0 && (x3 - x2) != 0) {
        float m1 = float(y2 - y1) / (x2 - x1);
        float m2 = float(y3 - y2) / (x3 - x2);
        if (abs(m1 * m2 + 1.0) < 1e-6) {
            isRightAngle = true;
        }
    }

    if ((x3 - x2) != 0 && (x3 - x1) != 0) {
        float m2 = float(y3 - y2) / (x3 - x2);
        float m3 = float(y3 - y1) / (x3 - x1);
        if (abs(m2 * m3 + 1.0) < 1e-6) {
            isRightAngle = true;
        }
    }

    if ((x2 - x1) != 0 && (x3 - x1) != 0) {
        float m1 = float(y2 - y1) / (x2 - x1);
        float m3 = float(y3 - y1) / (x3 - x1);
        if (abs(m1 * m3 + 1.0) < 1e-6) {
            isRightAngle = true;
        }
    }

    // Check for vertical and horizontal alignment directly
    if ((x2 == x1 && y3 == y2) || (x3 == x2 && y1 == y2) || (x3 == x1 && y2 == y3)) {
        isRightAngle = true;
    }

    if (isRightAngle) {
        cout << "Yes" << " ";
    } else {
        cout << "No" << " ";
    }

    return 0;
}
