#include<bits/stdc++.h>
using namespace std;

bool f(int mid,vector<int>t_i,int m){
    int sum=0;
    for(int i=0;i<t_i.size();i++){
        sum=mid/t_i[i]+sum;
    }
    if(sum>=m){
        return true;
    }
    return false;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<pair<int,pair<int,int>>>s;
    for (int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        s[i]=make_pair(a,make_pair(b,c));

    }
    sort(s.begin(),s.end());

    int l,r;
    l=0;
    r=m*s[n-1].first;
    int result=0;
    while(l<=r){
    int mid=(l+r)/2;
    int sum=0;
    int i=0;

    while(sum<=m){
        vector<int>t_i;
        sum=sum+mid/s[i].first;
        t_i.push_back(s[i].first);
        i++;
    }

    if(f(mid,t_i,m)){
        result=mid;
        mid=mid+1;

    }else{
        mid=mid-1;
    }

    }
    cout<<result;

}