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

Node* delete(Node* root, int val){
    if(root==NULL)
        return root;
    else if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->right!=NULL && root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        else{
            int min = minVal(root->right)->data; //right subtree me se min nikal lo
            root->data = min;
            root->right = delete(root->right,min);
            return root;
        }
    }
    else if(root->data>val){
        root->left = delete(root->left,val);
        return root;
    }
    else{
        root->right = delete(root->right,val);
        return root;
    }
}

int main()
{
    return 0;
}