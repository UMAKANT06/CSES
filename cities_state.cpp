#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int count=0;
    vector<pair<string,string>>pairs;
    map<string,int>m;
    for(int i=0;i<n;i++){
        string city;
        string code;
        cin>>city>>code;
        city=city.substr(0,2);
        pairs.push_back({city,code});
        
    }
    for (const auto &[c,s]:pairs){
        if(c!=s){
            m[s+c]++;
        }
        m[c+s]++;


    }
    for (const auto& [key, value] : m) {
        if (value > 1) {
            count++;
        }
    }
    cout<<count/2<<endl;
    return 0;
}