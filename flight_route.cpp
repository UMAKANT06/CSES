#include<bits/stdc++.h>
using namespace std;
void dfs(long long s,vector<bool>&visited,vector<vector<long long>>&adj,vector<int>&trav){
    visited[s]=true;
    trav.push_back(s);
    for(auto u:adj[s]){
        if(!visited[u]){
            dfs(u,visited,adj,trav);
        }
    }
}
int main(){
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>>adj(n+1);
    set<int>k;
    for(long long i=0;i<m;i++){
        long long a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        k.insert(a);
    }



    bool isConnected=true;
    for (long long j=1;j<=k.size();j++){
        vector<int>trav;
        vector<bool>visited(n+1,false);
        if(!visited[j]){
            dfs(j,visited,adj,trav);
        }

        
            if(trav.size()!=n){
                isConnected=false;
                break;
            }
        
    }

    if(isConnected==true){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}