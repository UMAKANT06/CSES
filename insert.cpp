#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,x;
    cin>>n>>k>>x;
    vector<int>a;
    vector<int>b;
    for (int i=0;i<n;i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    int c=0;
    for(int j=0;j<n+1;j++){
        if(j==k){
            b.push_back(x);

        }else{
        b.push_back(a[c]);
        c++;
        }

    }
    for(int m=0;m<n+1;m++){
        cout<<b[m]<<" ";
    }
    return 0;
}