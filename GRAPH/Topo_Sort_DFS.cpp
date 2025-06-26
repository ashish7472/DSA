#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>>adj;

        void addEdge(int u,int v){
            adj[u].push_back(v);
        }

        //isko apn topo sort se pahle graph me cycle to nhi h ye detection ke liye use kr sakte h
        bool hasCycleDFS(vector<bool>& vis, int src,int parent){
            vis[src] = 1;

            for(auto neighbour : adj[src]){
                if(!vis[neighbour]){
                    if(hasCycleDFS(vis,neighbour,src)){
                        return true;
                    }
                }
                else if(vis[neighbour] && neighbour != parent){
                    return true;
                }
            }
            return false;
        }

        //overall logic of topo sort assuming only one component of graph
        void topological(vector<bool>& vis, int src, stack<int>& ans){
            vis[src] = 1;
            
            for(auto neig : adj[src]){
                if(!vis[neig]){
                    topological(vis,neig,ans);
                }
            }

            ans.push(src);
        }
};

int main()
{
    Graph g;
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    vector<bool>vis(n,0);
    stack<int>ans;
    g.topological(vis,0,ans);


    //FOR DISCONNECTED GRAPH
    
    // for (int i = 0; i < n; i++) {
    //     if (!vis[i]) {
    //         g.topological(vis, i, ans);
    //     }
    // }

    while(!ans.empty()){
        cout<<ans.top()<<", ";
        ans.pop();
    }

}