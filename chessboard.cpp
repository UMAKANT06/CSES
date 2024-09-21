#include<bits/stdc++.h>
using namespace std;

bool isValid(int i,int j,char (&arr)[10][10]){
    if(i>=8||i<0||j>=8||j<0){
        return false;
    }
    for(int k=0;k<8;k++){
        if(arr[i][k]=='q'){
            return false;
        }
    }
    for(int k=0;k<8;k++){
        if(arr[k][j]=='q'){
            return false;
        }
    }
    for (int x = i, y = j; x >= 0 && y >= 0; x--, y--) {
        if (arr[x][y] == 'q') {
            return false;
        }
    }
    for (int x = i, y = j; x < 8 && y < 8; x++, y++) {
        if (arr[x][y] == 'q') {
            return false;
        }
    }

    
    for (int x = i, y = j; x >= 0 && y < 8; x--, y++) {
        if (arr[x][y] == 'q') {
            return false;
        }
    }
    for (int x = i, y = j; x < 8 && y >= 0; x++, y--) {
        if (arr[x][y] == 'q') {
            return false;
        }
    }

    
    return true;
}

void solve(int i,char (&arr)[10][10],int &count){
    if(i==8){
        count++;
        return;
    }

    for(int j=0;j<8;j++){
        if(arr[i][j]=='.'&&isValid(i,j,arr)){
            arr[i][j]='q';
            solve(i+1,arr,count);
            arr[i][j]='.';
        }
    }
}
int main(){
    char arr[10][10];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            char c;
            cin>>c;
            arr[i][j]=c;
        }
    }
    int count=0;
    solve(0,arr,count);
    cout<<count<<endl;

}