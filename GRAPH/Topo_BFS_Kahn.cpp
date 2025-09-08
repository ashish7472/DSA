//ALGO FOR KAHN'S ALGO :--->
//adjancy list make
//indegree calculate
//0 walo ko queue me push karo
//fhir normal bfs

//doesn't require visited array

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
        }

        void kahn(int n,int src,vector<int>& topo){

            //Indegree store
            vector<int>indegree(n);   
            for(auto node : adj){
                for(auto neigh : node.second){
                    indegree[neigh]++;
                }
            }

            //push 0 indegree in the queue.
            queue<int>q;
            for(int i=0;i<indegree.size();i++){
                if(indegree[i]==0) q.push(i);
            }

            //Do BFS
            while(!q.empty()){
                int front = q.front();
                q.pop();

                topo.push_back(front);

                //neighbour's indegree update
                for(auto neigh : adj[front]){
                    indegree[neigh]--;

                    if(indegree[neigh]==0){
                        q.push(neigh);
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
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    vector<int>topo;
    g.kahn(n,0,topo);

    for(auto it : topo){
        cout<<it<<", ";
    }cout<<endl;

}