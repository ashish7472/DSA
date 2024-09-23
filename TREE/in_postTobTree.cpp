// BINARY TREE CONSTRUCTION USING INORDER AND POSTORDER

class Solution {
private:
    //to store the index of every node 
    //same map concept we can use in inorder and preorder approach
    void createMapping(vector<int>& in,map<int,int>& m,int n){
        for(int i=0;i<n;i++){
            m[in[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& in,vector<int>& post,int& pEnd,
                        int inS,int inE,int n,map<int,int>& m){
        if(pEnd<0 || inS>inE){
            return NULL;
        }
        int element = post[pEnd--];
        TreeNode* root = new TreeNode(element);
        int pos = m[element];

        root->right = solve(in,post,pEnd,pos+1,inE,n,m);
        root->left = solve(in,post,pEnd,inS,pos-1,n,m);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pEnd = postorder.size()-1;
        int n = pEnd + 1;
        map<int,int>m;   //to reduce time complexity.
        createMapping(inorder,m,n);
        TreeNode* ans = solve(inorder,postorder,pEnd,0,n-1,n,m);
        return ans;
    }
};