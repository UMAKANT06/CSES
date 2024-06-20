#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, t, k;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0, s = 0;
    int l = 0, r = 0;
    while(r<n){
        s=s+a[r];
        while(s>t&&l<r){
            s=s-a[l];
            l++;
        }

        if(s==t){
            count++;
        }
        r++;

    }
    cout<<count<<endl;
    return 0;
}