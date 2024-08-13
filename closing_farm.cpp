#include <bits/stdc++.h>
using namespace std;

void dfs(int s, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& trav) {
    if (!visited[s]) {
        visited[s] = true;
        trav.push_back(s);
        for (auto u : adj[s]) {
            if (!visited[u]) {
                dfs(u, visited, adj, trav);
            }
        }
    }
}

void dfs1(int s, vector<bool>& visited1, vector<vector<int>>& second, vector<int>& trav1) {
    if (!visited1[s]) {
        visited1[s] = true;
        trav1.push_back(s);
        for (auto u : second[s]) {
            if (!visited1[u]) {
                dfs1(u, visited1, second, trav1);
            }
        }
    }
}

void removeNode(int node, vector<vector<int>>& second) {
    // Remove all edges to and from the node
    second[node].clear();
    for (auto& neighbors : second) {
        neighbors.erase(remove(neighbors.begin(), neighbors.end(), node), neighbors.end());
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> trav;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int j = 0; j < n; j++) {
        vector<vector<int>> second = adj;
        vector<int> trav1;
        int k;
        cin >> k;
        removeNode(k, second);
        vector<bool> visited1(n + 1, false);
        if (k == 1) {
            dfs1(2, visited1, second, trav1);
        } else {
            dfs1(1, visited1, second, trav1);
        }
        if (trav1.size() == n - 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    dfs(1, visited, adj, trav);

    if (trav.size() == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
