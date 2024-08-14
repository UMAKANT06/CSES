#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> dis(n + 1, -1);

    // Input graph edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> set1;
    vector<int> set2;
    queue<int> q;

    // Partitioning the tree into two sets using BFS
    for (int i = 1; i <= n; i++) {
        if (dis[i] == -1) {
            q.push(i);
            dis[i] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();

                if (dis[v] % 2 == 0) {
                    set1.push_back(v);
                } else {
                    set2.push_back(v);
                }
                
                for (auto u : adj[v]) {
                    if (dis[u] == -1) {
                        dis[u] = dis[v] + 1;
                        q.push(u);
                    }
                }
            }
        }
    }

    // Maximum edges that can be added
    long long max_edges = (long long)set1.size() * set2.size() - (n - 1);
    cout << max_edges << endl;

    return 0;
}
