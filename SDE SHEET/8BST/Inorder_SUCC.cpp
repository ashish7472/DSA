//INORDER SUCCESSOR
class Solution
{
public:
    TreeNode *inorder Successor(TreeNode *root, TreeNode *p)
    {
        TreeNode✶ successor = NULL;
        while (root != NULL)
        {
            if (p->val >= root->val)
                root = root->right;
            else{
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }
};

//INORDER PREDECESSOR

class Solution {
public:
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
        TreeNode* predecessor = NULL;
        while (root != NULL) {
            if (p->val <= root->val) {
                root = root->left;
            } else {
                predecessor = root;
                root = root->right;
            }
        }
        return predecessor;
    }
};
