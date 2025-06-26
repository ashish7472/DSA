#include <iostream>
#include <vector>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    vector<int> dist(V, 1e9); // Initialize distances
    dist[src] = 0;

    // Step 1: Relax all edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (auto edge : edges) {
            if (dist[edge.u] != 1e9 && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    // Step 2: Check for negative-weight cycles
    bool hasNegativeCycle = false;
    for (auto edge : edges) {
        if (dist[edge.u] != 1e9 && dist[edge.u] + edge.weight < dist[edge.v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Graph contains a negative weight cycle\n";
    } else {
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "To vertex " << i << " = ";
            if (dist[i] == 1e9) cout << "INF\n";
            else cout << dist[i] << "\n";
        }
    }
}

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3},  {1, 3, 2},
        {1, 4, 2},  {3, 2, 5},
        {3, 1, 1},  {4, 3, -3}
    };

    int src = 0; // Source vertex
    bellmanFord(V, E, edges, src);

    return 0;
}