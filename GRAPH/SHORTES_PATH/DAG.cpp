#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<pair<int,int>>>adj;   //<src, {dest,wt}>

        void addEdge(int u,int v,int wt){
            adj[u].push_back({v,wt});
        }

        void printG(){
            for(auto node : adj){
                cout<<node.first<<" -> ";
                for(auto neigh : node.second){
                    cout<<"{"<<neigh.first<<","<<neigh.second<<"}";
                }cout<<endl;
            }
        }

        void topo(vector<bool>& vis, int src, stack<int>& st){  //dfs topo to get the stack
            vis[src] = 1;

            for(auto neigh : adj[src]){
                if(!vis[neigh.first]){
                    topo(vis,neigh.first,st);
                }
            }

            st.push(src);
        }

        //SHORTEST DISTANCE FROM A SRC TO EACH NODE IN DIRECTED ACYCLIC GRAPH
        void shortest(int src, stack<int>& st, vector<int>& dis){
            dis[src] = 0;

            while(!st.empty()){
                int node = st.top();
                st.pop();

                if(dis[node] != INT16_MAX){
                    for(auto neigh : adj[node]){
                        dis[neigh.first] = min(dis[neigh.first], dis[node]+neigh.second);
                    }
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
        int u,v,wt;
        cin>>u>>v>>wt;
        g.addEdge(u,v,wt);
    }

    vector<bool>vis(n,0);

    stack<int>st;
    g.topo(vis,1,st);  //topo ke liye to src koi bhi ho sakti h

    g.printG();


    vector<int>dis(n,INT16_MAX);
    g.shortest(1,st,dis);   //src = 1

    for(auto it : dis){
        cout<<it<<", ";
    }cout<<endl;

}