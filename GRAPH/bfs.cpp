void bfs (unordered_map<int, list<int> > &adjList, unordered_map<int, bool > &visited,
vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        // store frontNode into ans
        anss.push_back.(frontNode);
        // traverse all neighbours of frontNode
        for (auto i : adj List[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

main(){
    //if it is the case of the multiple components then we have to call this above bfs function inside the for loop in main to make sure that our code run for all components of the graph.
    //if multiple components are not there then we can write this code directily inside the main without using any parent for loop for the dfs logic

    // SAME LOGIC GOES FOR THE DFS.
}