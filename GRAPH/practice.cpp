#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<list<int>>& adList,int u,int v){
    adList[u].push_back(v);
    adList[v].push_back(u);
}

void print(vector<list<int>>& adList){
    for(int i = 0;i<adList.size();i++){
        cout<<"Vertex "<<i<<": ";
        for(auto it : adList[i]){
            cout<<"->"<<it;
        }
        cout<<endl;
    }
}

int main()
{
    int vert = 5;
    vector<list<int>>adList(vert);

    addEdge(adList,0,1);
    addEdge(adList,1,2);
    addEdge(adList,0,3);
    addEdge(adList,2,4);
    addEdge(adList,4,3);
    // addEdge(adList,3,4);

    print(adList);
    return 0;
}