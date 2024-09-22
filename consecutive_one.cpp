#include<bits/stdc++.h>
using namespace std;
void solve(int n,string s,int i,vector<string>&ans){

    if(s.length()==n){
        ans.push_back(s);
        return;
    }

    s=s+'0';
    solve(n,s,i+1,ans);
    s.pop_back();
    if(i==0 || s[i-1]!='1'){
        s=s+'1';
        solve(n,s,i+1,ans);
        s.pop_back();
    }
    
}
int main(){
    int n;
    cin>>n;
    vector<string>ans;
    string s;
    solve(n,s,0,ans);
    cout<<ans.size()<<endl;
}