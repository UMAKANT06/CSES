#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> set1;
        vector<int> set2;
        vector<int> distance(n + 1, -1);
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (distance[i] == -1) {
                q.push(i);
                distance[i] = 0;

                while (!q.empty()) {
                    int v = q.front();
                    q.pop();

                    if (distance[v] % 2 == 0) {
                        set1.push_back(v);
                    } else {
                        set2.push_back(v);
                    }
                    for (auto u : adj[v]) {
                        if (distance[u] == -1) {
                            distance[u] = distance[v] + 1;
                            q.push(u);
                        }
                    }
                }
            }
        }

        if (set1.size() <= n / 2) {
            cout << set1.size() << endl;
            for (int i = 0; i < set1.size(); i++) {
                cout << set1[i] << " ";
            }
            cout << endl;
        } else {
            cout << set2.size() << endl;
            for (int i = 0; i < set2.size(); i++) {
                cout << set2[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
