#include<bits/stdc++.h>
using namespace std;
const int MAX_INT=1000;
char arr[MAX_INT][MAX_INT];
int n;
bool visited[MAX_INT][MAX_INT];

void floodfill(int i,int j,int &curr_size){
    if(i<0||i>=n||j<0||j>=n||visited[i][j]==true||arr[i][j]=='.'){
        return;
    }
    visited[i][j]=true;
    curr_size++;

    floodfill(i + 1, j,curr_size);
    floodfill(i - 1, j,curr_size);
    floodfill(i, j + 1,curr_size);
    floodfill(i, j - 1,curr_size);
}
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int max_area=0;

    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='#'&&visited[i][j]==false){
                int curr_size=0;
                floodfill(i,j,curr_size);
                max_area=max(max_area,curr_size);
            }
        }
    }

    cout<<max_area;
}