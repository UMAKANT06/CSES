#include <bits/stdc++.h>
using namespace std;

const int MAX_INT = 1000;

int m, n;
int arr[MAX_INT][MAX_INT];
bool visited[MAX_INT][MAX_INT];
int way[MAX_INT][MAX_INT];

void floodfill(int i,int j){
    if(i<0||i>=m||j<0||j>=n||visited[i][j]==true){
        return;
    }
    visited[i][j]=true;
   int x1=abs(arr[i][j]-arr[i+1][j]);
   int x2=abs(arr[i][j]-arr[i-1][j]);
   int x3=abs(arr[i][j]-arr[i][j+1]);
   int x4=abs(arr[i][j]-arr[i][j-1]);
   
}
int main() {
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> way[i][j];
        }
    }


    return 0;
}


