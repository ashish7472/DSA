vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;   //{src, {dest, wt}}
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Initialize dist vector with infinite
    vector<int> dist(vertices, INT_MAX);

    // Min-heap priority queue (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        // Fetch top record
        auto top = pq.top();
        pq.pop();
        int nodeDistance = top.first;
        int topNode = top.second;

        // Traverse on neighbours
        for (auto neighbour : adj[topNode]) {
            if (nodeDistance + neighbour.second < dist[neighbour.first]) {
                // Distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // Push updated distance into the priority queue
                pq.push(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
} 