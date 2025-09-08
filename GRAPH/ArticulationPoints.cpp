#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

void dfs(int node, int parent, vector<int> &discT, vector<int> &low, vector<bool> &visited,
        unordered_map<int, list<int>> &adj, vector<bool> &isAP, int &timer) {

    visited[node] = true;
    discT[node] = low[node] = timer++;
    int childCount = 0;

    for (auto neighbour : adj[node]) {
        if (neighbour == parent) continue; //ignore it

        if (!visited[neighbour]) {
            dfs(neighbour, node, discT, low, visited, adj, isAP, timer);
            low[node] = min(low[node], low[neighbour]); //while(after) returning 

            // Non-root articulation point condition
            if (low[neighbour] >= discT[node] && parent != -1) { // condn for articulation point
                isAP[node] = true;
            }

            childCount++;
        } else { //if visited
            // Back edge
            low[node] = min(low[node], discT[neighbour]);
        }
    }

    // Root articulation point condition ki agar child 1 se > then wo to ap h hi
    if (parent == -1 && childCount > 1) {
        isAP[node] = true;
    }
}

vector<int> findArticulationPoints(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;

    // Build adjacency list
    for (int i = 0; i < e; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> discT(v, -1);
    vector<int> low(v, -1);
    vector<bool> visited(v, false);
    vector<bool> isAP(v, false);
    int timer = 0;
    int parent = -1;

    // Handle disconnected graph
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            dfs(i, parent, discT, low, visited, adj, isAP, timer);
        }
    }

    // Collect articulation points
    vector<int> result;
    for (int i = 0; i < v; ++i) {
        if (isAP[i]) result.push_back(i);
    }

    return result;
}