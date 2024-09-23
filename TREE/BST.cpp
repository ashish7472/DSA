#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

Node* insertIntoBST(Node* root, int d){
    if(!root){
        root = new Node(d);
        return root;
    }
    if(d>root->data)
        root->right = insertIntoBST(root->right,d);
    else
        root->left = insertIntoBST(root->left,d);

    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

int main()
{
    Node* root  = NULL;

    cout<<"Enter data for BST: "<<endl;
    takeInput(root);

    return 0;
}

//and after this we can traverse it using any traversal method.