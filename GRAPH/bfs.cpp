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
        ans.push_back.(frontNode);
        // traverse all neighbours of frontNode
        for (auto i : adjList[frontNode])
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
    //if multiple components are not there then we can write this code directily inside the main without using any parent for-loop for the bfs logic
    
    // int nodes;
    // if(int i=0;i<nodes;i++){
    //     if(!vis[i]){  
    //         bfs();
    //     }
    // }

    // SAME LOGIC GOES FOR THE DFS.
}