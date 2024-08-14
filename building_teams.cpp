#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int start, vector<vector<int>>& adj, vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 0; // Start coloring with 0

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (color[u] == -1) { // If not colored
                // Assign alternate color
                color[u] = 1 - color[v];
                q.push(u);
            } else if (color[u] == color[v]) {
                // Same color as the current node means it's not bipartite
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // adjacency list
    vector<int> color(n + 1, -1); // color array, -1 means uncolored

    // Input edges
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Check bipartiteness for each component
    bool bipartite = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) { // Not visited yet
            if (!isBipartite(i, adj, color)) {
                bipartite = false;
                break;
            }
        }
    }

    if (bipartite==false){cout<<"IMPOSSIBLE"<<endl;
    return 0;
    }

    for(int i=1;i<=n;i++){
        if(color[i]==0){
            cout<<"1"<<" ";
        }else{
            cout<<"2"<<" ";
        }
    }

    return 0;
}



// queue<int> q;
//     bool bipartite = true; // To check if the graph is bipartite
//     vector<int> set1, set2; // Two sets to store nodes based on distance parity

//     // Initialize BFS
//     for (int i = 1; i <= n; i++) {
//         if (distance[i] == -1) { // Not visited yet
//             q.push(i);
//             distance[i] = 0; // Start with distance 0

//             while (!q.empty()) {
//                 int v = q.front();
//                 q.pop();

//                 // Based on distance, add to the appropriate set
//                 if (distance[v] % 2 == 0) {
//                     set1.push_back(v);
//                 } else {
//                     set2.push_back(v);
//                 }

//                 for (int u : adj[v]) {
//                     if (distance[u] == -1) { // If not visited
//                         distance[u] = distance[v] + 1;
//                         q.push(u);
//                     } else if (distance[u] % 2 == distance[v] % 2) {
//                         // If nodes at the same level are connected, it's not bipartite
//                         bipartite = false;
//                     }
//                 }
//             }
//         }
//     }

//     if (bipartite) {
//         cout << "The graph is bipartite." << endl;
//         cout << "Set 1: ";
//         for (int node : set1) {
//             cout << node << " ";
//         }
//         cout << endl;

//         cout << "Set 2: ";
//         for (int node : set2) {
//             cout << node << " ";
//         }
//         cout << endl;
//     } else {
//         cout << "The graph is not bipartite." << endl;
//     }
