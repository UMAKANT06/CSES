#include<bits/stdc++.h>
using namespace std;

void dfs(int s, vector<bool>& visited, vector<vector<int>>& adj) {
    
    visited[s] = true;
    
    for (auto u : adj[s]) {
        if (!visited[u]) {
            dfs(u, visited, adj);
        }
    
    }
}

bool isConnected(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false);

    // Start DFS from node 1 (or any node with at least one connection)
    dfs(0, visited, adj);

    // Check if all nodes are visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
   
        int p, c;
        cin >> p >> c;
        vector<vector<int>> adj(p + 1);
        vector<pair<int, int>> edges;
        
        for (int i = 0; i < c; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            edges.push_back({a, b});
        }
        
        bool isBridge = false;
        
        for (auto edge : edges) {
            int a = edge.first;
            int b = edge.second;
        
            
            // Remove edge (a, b)
            adj[a].erase(remove(adj[a].begin(), adj[a].end(), b), adj[a].end());
            adj[b].erase(remove(adj[b].begin(), adj[b].end(), a), adj[b].end());

            

            
            if (!isConnected(p, adj)) {
                isBridge = true;
                break;
            }
            
            // Restore the edge (a, b)
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        if (isBridge) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    
    return 0;
}
