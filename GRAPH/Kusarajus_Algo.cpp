//ALGO TO FIND STRONGLY CONNECTED COMPONENTS IN A GRAPH

#include<unordered_map>
#include<stack>
#include<list>
void createList(vector<vector<int>>& edges, unordered_map<int, list<int>>& adjList) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
}
void topoSort(int vtx, vector<bool>& visited, stack<int>& st, unordered_map<int, list<int>>& adjList) {
    visited[vtx] = true;
    for (auto neighbor: adjList[vtx]) {
        if (!visited[neighbor]) {
            topoSort(neighbor, visited, st, adjList);
        }
    }
    st.push(vtx);
}
void countSCCsDFS(int vtx, vector<bool>& visited, unordered_map<int, list<int>>& transposeAdjList) {
    visited[vtx] = true;
    for (auto neighbor: transposeAdjList[vtx]) {
        if (!visited[neighbor]) {
            countSCCsDFS(neighbor, visited, transposeAdjList);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adjList;
    createList(edges, adjList);
    // topo sort
    vector<bool> visited(v, false);
    stack<int> st;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topoSort(i, visited, st, adjList);
        }
    }
    // create a transpose graph
    unordered_map<int, list<int>> transposeAdjList;
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        for (auto neighbor: adjList[i]) {
            transposeAdjList[neighbor].push_back(i);
        }
    }
    // dfs call using transposeAdjList graph
    // sccs: strongly connected component(s)
    int countSCCs = 0;
    while (!st.empty()) {
        int topVtx = st.top();
        st.pop();
        if (!visited[topVtx]) {
            countSCCs++;
            countSCCsDFS(topVtx, visited, transposeAdjList);
        }
    }
    // no. of strongly connected component(s)
    return countSCCs;
}