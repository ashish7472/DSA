void dfsTraversal(const std::vector<std::list<int>>& adjList, int vertex, std::vector<bool>& visited) {
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
