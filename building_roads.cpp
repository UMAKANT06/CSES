#include <bits/stdc++.h>
using namespace std;

// Depth-First Search function to explore all nodes in a component
void dfs(int s, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& trav) {
    visited[s] = true;
    trav.push_back(s);
    for (int u : adj[s]) {
        if (!visited[u]) {
            dfs(u, visited, adj, trav);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // Input the number of cities (nodes) and roads (edges)

    vector<vector<int>> adj(n + 1);   // Adjacency list for the graph
    vector<bool> visited(n + 1, false); // Visited array to track visited nodes

    // Read the roads (edges)
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  // Since the graph is undirected
    }

    vector<int> representatives;  // To store one representative node from each component

    // Find all components and store one representative from each
    for (int i = 1; i <= n; i++) {  // Cities are numbered from 1 to n
        if (!visited[i]) {
            vector<int> trav;
            dfs(i, visited, adj, trav);
            representatives.push_back(i);  // Store the first node of the component
        }
    }

    int roads_needed = representatives.size() - 1;  // Roads needed to connect all components

    // Output the number of roads needed
    cout << roads_needed << endl;

    // Output the roads to be added
    for (int i = 1; i < representatives.size(); i++) {
        cout << representatives[i - 1] << " " << representatives[i] << endl;
    }

    return 0;
}
