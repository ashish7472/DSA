//BINARY TREE CONSTRUCTION BY USING INORDER AND PREORDER

class Solution {
private:
    int findPosition(vector<int>inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element){
                return i;
                break;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int& preInd,int startInInd,int endInInd,int n){
        if(preInd>=n || startInInd>endInInd)
            return NULL;
        
        int element = preorder[preInd++];
        TreeNode* root = new TreeNode(element);
        int pos = findPosition(inorder,element); //for optimisation apn ye map bhi bana sakte h of inorder
        root->left = solve(preorder,inorder,preInd,startInInd,pos-1,n);
        root->right = solve(preorder,inorder,preInd,pos+1,endInInd,n);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preInd = 0;
        TreeNode* ans = solve(preorder,inorder,preInd,0,n-1,n);
        return ans;
    }
};