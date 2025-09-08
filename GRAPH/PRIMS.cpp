#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> g) {
    // Create adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Let's start the algo
    //src node 
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++) {
        int mini = INT_MAX;
        int u;

        // Find the min wali node
        for (int v = 1; v <= n; v++) {
            if (!mst[v] && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        // Mark as included in MST
        mst[u] = true;

        // Check its adjacent nodes
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (!mst[v] && w < key[v]) { //and update parent and key
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main() {
    int n = 5; // number of nodes
    int m = 6; // number of edges
    vector<pair<pair<int, int>, int>> g = {
        {{1, 2}, 2},
        {{1, 3}, 4},
        {{2, 3}, 1},
        {{2, 4}, 7},
        {{3, 5}, 3},
        {{4, 5}, 1}
    };

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, g);

    cout << "Edges in MST:\n";
    for (auto edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}