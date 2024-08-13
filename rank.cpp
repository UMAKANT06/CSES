#include<bits/stdc++.h>
using namespace std;

bool cycle(int s, vector<bool>& visited, vector<bool>& recStack, vector<vector<int>>& adj, vector<int>& cyc) {
    visited[s] = true;
    recStack[s] = true;

    for (auto u : adj[s]) {
        if (!visited[u]) {
            if (cycle(u, visited, recStack, adj, cyc)) {
                cyc.push_back(u);  // Store the node in the cycle
                if (u == s) return false; // Stop adding nodes once we complete the cycle
                return true;
            }
        } else if (recStack[u]) {
            cyc.push_back(u); // Start storing nodes when a back edge is found
            return true;
        }
    }

    recStack[s] = false; // Remove the node from the recursion stack
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<bool> recStack(n + 1, false);
    set<int> nodes;
    vector<vector<int>>multi_cycles;
    for (int i = 0; i < k; i++) {
        int a, b, s_a, s_b;
        cin >> a >> b >> s_a >> s_b;
        nodes.insert(a);
        nodes.insert(b);
        if (s_a > s_b) {
            adj[b].push_back(a);
        } else {
            adj[a].push_back(b);
        }
    }

    vector<int> cyc;
    for (auto node : nodes) {
        if (!visited[node]) {
            if (cycle(node, visited, recStack, adj, cyc)) {
                cyc.push_back(node); // Include the starting node of the cycle
            }
        }
    }

    for (int i=0;i<cyc.size();i++){
        cout<<cyc[i]<<" ";
    }
    return 0;


}
