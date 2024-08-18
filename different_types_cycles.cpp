#include<bits/stdc++.h>
using namespace std;
bool isCyclicUtil(int node, vector<bool> &visited, vector<bool> &recStack, vector<vector<int>> &adj, vector<int> &path, vector<vector<int>> &allCycles) {
    visited[node] = true;
    recStack[node] = true;
    path.push_back(node);
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (isCyclicUtil(neighbor, visited, recStack, adj, path, allCycles))
                return true;
        } else if (recStack[neighbor]) {
            // Cycle detected, store the cycle
            vector<int> cycle;
            auto it = find(path.begin(), path.end(), neighbor);
            cycle.insert(cycle.end(), it, path.end());
            cycle.push_back(neighbor);
            allCycles.push_back(cycle);
        }
    }
    
    path.pop_back();
    recStack[node] = false;
    return false;
}

vector<vector<int>> findAllCycles(int n, vector<vector<int>> &adj) {
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);
    vector<vector<int>> allCycles;
    vector<int> path;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            isCyclicUtil(i, visited, recStack, adj, path, allCycles);
        }
    }

    return allCycles;
}
