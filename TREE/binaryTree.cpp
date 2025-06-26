#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

node* buildTree(node* root){
    int data;
    cout<<"Enter data for node: ";
    cin>>data;
    root = new node(data);

    if(data==-1)
        return NULL;
    
    cout<<"Enter data for left child: ";
    root->left = buildTree(root->left);
    cout<<"Enter data for right child: ";
    root->right = buildTree(root->right);

    return root;

}

//BFS Traversal(level order traversal)
void bfs(node* root){
    queue<node*>q;
    q.push(root);
    

    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

int main()
{
    node* root = NULL;
    
    //creating a tree;
    root = buildTree(root);

    bfs(root);
    return 0;
}