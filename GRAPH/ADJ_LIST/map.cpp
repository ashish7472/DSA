#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<int, vector<int>> adjList;

    // Adding edges
    adjList[0] = {1, 2};
    adjList[1] = {2};
    adjList[2] = {3};
    adjList[3] = {4};

    // Print adjacency list for each vertex
    for (const auto& pair : adjList) {
        cout << "Vertex " << pair.first << ": ->";
        for (int neighbor : pair.second) {
            cout <<neighbor<<", ";
        }
        cout << endl;
    }

    return 0;
}
