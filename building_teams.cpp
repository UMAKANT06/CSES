#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and color the graph
bool dfs(int s, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& color) {
    visited[s] = true;
    for (auto u : adj[s]) {
        if (!visited[u]) {
            // Assign alternate color to adjacent nodes
            color[u] = 1 - color[s]; // If color[s] is 0, color[u] will be 1, and vice versa
            if (!dfs(u, visited, adj, color)) {
                return false; // If adjacent node coloring fails, return false
            }
        } else if (color[u] == color[s]) {
            return false; // If adjacent nodes have the same color, graph is not bipartite
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // adjacency list
    vector<bool> visited(n + 1, false); // visited array
    vector<int> color(n + 1, -1); // color array, -1 means uncolored

    // Input edges
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // To ensure all components are covered
    bool isBipartite = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            color[i] = 0; // Start coloring from 0
            if (!dfs(i, visited, adj, color)) {
                isBipartite = false;
                break;
            }
        }
    }

    // Output the result
    if (isBipartite) {
        for (int i = 1; i <= n; i++) {
            // Output 1 or 2 based on the color
            cout << (color[i] == 0 ? 1 : 2) << " ";
        }
        cout << endl;
    } else {
        cout << "Graph is not bipartite" << endl;
    }

    return 0;
}
