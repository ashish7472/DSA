class Solution {
private:
    TreeNode* helper(vector<int>& preorder, int upper_bound, int& i){
        if(i==preorder.size() || preorder[i]>upper_bound){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = helper(preorder,root->val, i); //lc ke liye ub root->val hogi
        root->right = helper(preorder,upper_bound,i); //rc ke liye ub change nhi hoga

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int upper_bound = INT_MAX;
        int i = 0;
        return helper(preorder,upper_bound,i);
    }
};