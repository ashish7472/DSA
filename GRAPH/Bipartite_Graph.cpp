//BFS
class Solution {
private:    
    bool bfs(int src, vector<vector<int>>& graph, vector<int>& color){
        color[src] = 0;
        queue<pair<int,int>>q;//{node,color} //we can only take queue<int> coz we're already storing color in colro array
        q.push({src,0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int currColor = it.second;

            for(int neigh : graph[node]){
                if(color[neigh]==-1){//assign opposite color to node
                    int c = 1 - color[node];
                    color[neigh] = c;
                    q.push({neigh,c});
                }
                else{ //pahle se colored h neigh node ka
                    if(color[neigh]==color[node]) return false;
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int>color(nodes,-1);

        for(int i=0;i<nodes;i++){
            if(color[i]==-1){//not yet colored
                if(!bfs(i,graph,color)) return false;
            }
        }

        return true;
    }
};


//DFS
lass Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int currColor) {
        color[node] = currColor;

        for (int neigh : graph[node]) {
            if (color[neigh] == -1) {
                // Assign opposite color recursively
                if (!dfs(neigh, graph, color, 1 - currColor))
                    return false;
            } 
            else if (color[neigh] == color[node]) {
                // Conflict found → not bipartite
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = uncolored, 0/1 = two colors

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // not visited yet
                if (!dfs(i, graph, color, 0))
                    return false;
            }
        }
        return true;
    }
};
