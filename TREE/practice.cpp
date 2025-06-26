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

Node* maxi(Node* root){
    if(!root || !root->right) return root;
    return maxi(root->right);
}

Node* deleteN(Node* root, int key){
    if(root == NULL) return NULL;

    if(key < root->val){
        root->left = deleteN(root->left, key);  // ✅ UPDATE HERE
    }
    else if(key > root->val){
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
        int d = maxi(root->left)->val;
        root->val = d;
        root->left = deleteN(root->left, d);  // ✅ recursive deletion
    }
    return root;
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

bool search(Node* root,int key){
    if(root==NULL) return 0;
    if(root->val==key) return 1;
    if(key>root->val) return search(root->right,key);
    return search(root->left,key);
}

int main()
{
    Node* root = NULL;
    takeInput(root);

    bfs(root);
    cout<<endl;
    deleteN(root,70);
    bfs(root);
    return 0;
}