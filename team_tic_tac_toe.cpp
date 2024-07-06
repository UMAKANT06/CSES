#include<bits/stdc++.h>
using namespace std;
int main(){
    const int rows = 3;  // Number of lines
    const int cols = 3;  // Number of characters per line

    std::vector<std::vector<char>> array(rows, std::vector<char>(cols));

    // Read the input lines and store them in the 2D array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> array[i][j];
        }
    }
    int count_one,count_two=0;
    for (int i=0;i<3;i++ ){
        set<char>r;
        for(int j=0;j<3;j++){
            r.insert(array[i][j]);

        }
        if(r.size()==3){
            count_one++;
        }else if(r.size()==2){
            count_two++;
        }

    }
    for (int i=0;i<3;i++ ){
        set<char>c;
        for(int j=0;j<3;j++){
            c.insert(array[j][i]);

        }
        if(c.size()==3){
            count_one++;
        }else if(c.size()==2){
            count_two++;
        }

    }

    // Check main diagonal
    set<char> d1;
    for (int i = 0; i < rows; ++i) {
        d1.insert(array[i][i]);
    }
    if (d1.size() == 3) {
        count_one++;
    } else if (d1.size() == 2) {
        count_two++;
    }

    // Check anti-diagonal
    set<char> d2;
    for (int i = 0; i < rows; ++i) {
        d2.insert(array[i][cols - 1 - i]);
    }
    if (d2.size() == 3) {
        count_one++;
    } else if (d2.size() == 2) {
        count_two++;
    }

    cout<<count_one<<endl;
    cout<<count_two<<endl;
}