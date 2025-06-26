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

Node* maxi(Node* root){
    if(!root || !root->right) return root;
    return maxi(root->right);
}

Node* deleteN(Node* root, int key){
    if(root == NULL) return NULL;

    if(key < root->data){ 
        root->left = deleteN(root->left, key);  // ✅ UPDATE HERE
    }
    else if(key > root->data){
        root->right = deleteN(root->right, key);  // ✅ AND HERE
    }
    else {
        // 0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        // 1 child (left)
        if(!root->right && root->left){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 1 child (right)
        if(!root->left && root->right){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 children
        int d = maxi(root->left)->data;
        root->data = d;
        root->left = deleteN(root->left, d);  // ✅ recursive deletion
    }
    return root;
}

int main()
{
    return 0;
}