#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a;
    for (int i=0;i<n;i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    //sorting the array
    sort(a.begin(),a.end());


    // Initialize the minimum difference to a large value
    int min_diff = INT_MAX;

    // Case 1: Remove k elements from the start
    if (k < n) {
        min_diff = min(min_diff, a[n - 1] - a[k]);
    }

    // Case 2: Remove k elements from the end
    if (k < n) {
        min_diff = min(min_diff, a[n - k - 1] - a[0]);
    }

    //Remove k elements one by one

    int l=0;
    int min_=INT_MAX;
    int r=n-1;
    for (int j=0;j<k;j++){
        int r_d=abs(a[l]-a[r-1]);
        int l_d=abs(a[l+1]-a[r]);
        if(r_d>=l_d){
            min_=l_d;
            l++;

        }else{
            min_=r_d;
            r--;
        }
    }
    min_diff=min(min_,min_diff);
    cout<<min_diff<<" ";
    return 0;
}