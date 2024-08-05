#include<bits/stdc++.h>
using namespace std;

bool canMake(long long mid,long long n,vector<long long>& arr,long long t){

    long long sum=0;
    for (long long i=0;i<n;i++){
        sum=sum+(mid/arr[i]);
    }
    if(sum>=t){
        return true;
    }
    return false;


}

int main(){
    long long n,t,k;
    cin>>n>>t;
    vector<long long>arr;
    for (long long i=0;i<n;i++){
        cin>>k;
        arr.push_back(k);
    }
    sort(arr.begin(),arr.end());

    long long l=0;
    long long r=t*arr[n-1];
    long long result= r;

    while(l<=r){
        long long mid=(l+r)/2;
        if (canMake(mid, n, arr,t)) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout<< result;
    return 0;
}