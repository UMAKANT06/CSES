#include<bits/stdc++.h>
using namespace std;

const int max_n = 1000;
int n, m;
char arr[max_n][max_n];
bool visited[max_n][max_n];  

void floodfill(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == true || arr[i][j] == '#') {
        return;
    }

    visited[i][j] = true;

    floodfill(i + 1, j);
    floodfill(i - 1, j);
    floodfill(i, j + 1);
    floodfill(i, j - 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int count = 0;
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(arr[i][j] == '.' && !visited[i][j]) {
                floodfill(i, j);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
