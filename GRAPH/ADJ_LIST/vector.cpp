#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> adjList(V);  // Adjacency list representation

    // Adding edges
    adjList[0].push_back(1);  // Edge from vertex 0 to 1
    adjList[0].push_back(2);  // Edge from vertex 0 to 2
    adjList[1].push_back(2);  // Edge from vertex 1 to 2
    adjList[2].push_back(3);  // Edge from vertex 2 to 3
    adjList[3].push_back(4);  // Edge from vertex 3 to 4

    // Printing the adjacency list
    cout << "Graph (Adjacency List Representation):" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ":";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << " -> " << adjList[i][j];
        }
        cout << endl;
    }

    return 0;
}
