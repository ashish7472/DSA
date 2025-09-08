#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int graph[m][n] = {0}; //for 1 based use m+1,n+1

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //for undirected graph
        graph[u][v] = 1; 
        graph[v][u] = 1;
    }

    cout<<"Graph : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}