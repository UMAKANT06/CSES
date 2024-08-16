#include <bits/stdc++.h>
using namespace std;

void dfs(long long s, vector<bool>& visited, vector<vector<long long>>& adj) {
    visited[s] = true;
    for (auto u : adj[s]) {
        if (!visited[u]) {
            dfs(u, visited, adj);
        }
    }
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> adj(n + 1), adj_rev(n + 1);

    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);  // Reverse graph
    }

    vector<bool> visited(n + 1, false);

    // Step 1: DFS on original graph
    dfs(1, visited, adj);
    for (long long i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
    }

    // Step 2: DFS on reversed graph
    fill(visited.begin(), visited.end(), false);
    dfs(1, visited, adj_rev);
    for (long long i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0;
        }
    }

    // If both DFS traversals visit all cities, the graph is strongly connected
    cout << "YES" << endl;

    return 0;
}
