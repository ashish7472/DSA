class Solution {
private:
    bool isBST(TreeNode* root, long min, long max){
        if(root==NULL)
            return true;
        if(root->val > min && root->val < max){
            bool left = isBST(root->left,min,root->val);
            bool right = isBST(root->right,root->val,max);
            return left && right;
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root,INT_MIN,INT_MAX);
    }
};