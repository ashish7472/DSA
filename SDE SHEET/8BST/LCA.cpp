class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root;
        }
        int rvalue = root->val;
        if(p->val<rvalue && q->val<rvalue)
            return lowestCommonAncestor(root->left,p,q);
        if(p->val>rvalue && q->val>rvalue)
            return lowestCommonAncestor(root->right,p,q);
        
        return root; //there is split so return that intersectiong point(lca)
    }
};