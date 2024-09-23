#include<bits/stdc++.h>
using namespace std;

// Function to add an edge to the adjacency list
void addEdge(vector<list<int>>& adjList, int u, int v) {
    adjList[u].push_back(v); // Add v to u's list
    adjList[v].push_back(u); // Add u to v's list (for undirected graph)
}

// Function to print the adjacency list
void printAdjList(const vector<list<int>>& adjList) {
    for (int i = 0; i < adjList.size(); ++i) {
        cout << "Vertex " << i << ":";
        for (const auto& v : adjList[i]) {
            cout << " -> " << v;
        }
        cout << endl;
    }
}

//BFS TRAVERSAL
void bfsTraversal(const vector<list<int>>& adjList, int startVertex) {
    vector<bool> visited(adjList.size(), false); // Mark all vertices as not visited
                    
    queue<int> q; // Create a queue for BFS

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        // Dequeue a vertex from the queue and print it
        int vertex = q.front();
        cout << vertex << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited, mark it visited and enqueue it
        for (const auto& adjVertex : adjList[vertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                q.push(adjVertex);
            }
        }
    }
    cout << endl;
}

//DFS TRAVERSAL
void dfsTraversal(const vector<list<int>>& adjList, int vertex, vector<bool>& visited) {
    // Mark the current vertex as visited
    visited[vertex] = true;
    cout << vertex << " ";  // Process the vertex (e.g., print it)

    // Recur for all the adjacent vertices of the current vertex
    for (const auto& adjVertex : adjList[vertex]) {
        if (!visited[adjVertex]) {
            dfsTraversal(adjList, adjVertex, visited);
        }
    }
}


int main() {
    int numVertices = 5; // Number of vertices in the graph

    // Create an adjacency list with 'numVertices' vertices
    vector<list<int>> adjList(numVertices);
                    // OR
    // unordered_map<int,list<int>>adList;


    // Add edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    // Print the adjacency list
    printAdjList(adjList);

    //BFS Traversal.
    cout << "BFS traversal starting from vertex 0: ";
    bfsTraversal(adjList, 0);

    vector<bool> visited(adjList.size(), false);
    cout << "DFS traversal starting from vertex 0: ";
    dfsTraversal(adjList, 0,visited);

    return 0;
}
