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
    q.push(NULL); //seperator for printing tree in tree structure

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp==NULL){ //purana level completely traverse ho chuka h
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            else if(temp->right)
                q.push(temp->right);
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