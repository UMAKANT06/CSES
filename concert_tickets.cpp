#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k,p;
    cin>>n>>m;
    multiset<int>set;
    for (int i=0;i<n;i++){
        cin>>k;
        set.insert(k);
    }
    for(int j=0;j<m;j++){
        cin>>p;
        auto it=set.upper_bound(p);
        if(it==set.begin()){
            cout<<-1<<endl;
        }else{
            --it;
            cout<<*(it)<<endl;
            set.erase(it);
        }
    }
    return 0;
}