#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>>adj;

        void addEdge(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void printG(){
            for(auto i : adj){
                cout<<i.first<<" --> ";
                for(auto j : i.second){
                    cout<<j<<", ";
                }cout<<endl;
            }
        }

        void bfs(int n, int node, vector<bool>& vis){
            queue<int>q;
            q.push(node);
            vis[node] = true;

            while(!q.empty()){
                int val = q.front();
                cout<<val<<", ";
                q.pop();

                for(auto it : adj[val]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = true;
                    }
                }
            }
        }

        void dfs(int node, vector<bool>& vis){
            cout<<node<<", ";
            vis[node] = true;

            for(auto it : adj[node]){
                if(!vis[it]){
                    dfs(it,vis);
                }
            }
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

    g.printG();
    cout<<endl;

    vector<bool>vis(n,false);
    g.bfs(8,0,vis);                 //handle case of multiple components by just calling this func in a loop
    cout<<endl;

    fill(vis.begin(), vis.end(), false);
    g.dfs(0,vis);                  //handle case of multiple components by jjust calling this func in a loop
    return 0;
}