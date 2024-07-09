#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j,k,l;
    cin>>a>>b>>c>>d>>e>>f;
    cin>>g>>h>>i>>j>>k>>l;
    bool x_overlap = (a < j && d > g);
    bool y_overlap = (b < k && e > h);
    bool z_overlap = (c < l && f > i);

    if (x_overlap && y_overlap && z_overlap) {
        cout << "Yes" << " ";
    } else {
        cout << "No" << " ";
    }
    return 0;
}