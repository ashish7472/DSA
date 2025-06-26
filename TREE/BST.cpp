#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

        Node(int d){
            val = d;
            left = right = NULL;
        }
};

void insert(Node*& root,int val){
    if(!root){
        root = new Node(val);
    }
    if(val>root->val){
        insert(root->right,val);
    }
    if(val<root->val) insert(root->left,val);
}

void takeInput(Node*& root){
    int data;
    cin>>data;

    while(data != -1){
        insert(root,data);
        cin>>data;
    }
}

void bfs(Node* root){
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            Node* node = q.front();
            q.pop();
            cout<<node->val<<" ";

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
}

int main()
{
    Node* root = NULL;
    takeInput(root);

    bfs(root);
    cout<<endl;
    return 0;
}