void kahn(int n, vector<int>& topo) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; ++u) {
        for (auto v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) 
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (auto v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    if (topo.size() < n)
        cout << "Graph has a cycle\n";
    else
        cout << "Graph is acyclic\n";
}
