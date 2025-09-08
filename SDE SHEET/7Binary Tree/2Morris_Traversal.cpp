//INORDER MORRIS TRAVERSAL
class Solution {
public:
    vector<int> getInorder(TreeNode* root) {
        // inorder traversal result
        vector<int> inorder;
        TreeNode* cur = root;
        
        while (cur != NULL) {
            // left child is NULL
            if (cur->left == NULL) {
                inorder.push_back(cur->val);
                cur = cur->right;
            } else {
                //find predecessor calculation
                TreeNode* predecessor = cur->left;
                while (predecessor->right && predecessor->right != cur) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == NULL) {
                    predecessor->right = cur; //temp link making
                    cur = cur->left;
                } else {
                    predecessor->right = NULL; //temp link breaking
                    inorder.push_back(cur->val); //push when you return after finishing left
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};


//PREORDER MORRIS TRAVERSAL                            
class Solution {
public:
    vector<int> getPreorder(TreeNode* root) {
        //preorder result
        vector<int> preorder;
        TreeNode* cur = root;

        while (cur != NULL) {
            if (cur->left == NULL) {
                preorder.push_back(cur->val);
                cur = cur->right;
            } else {
                //find predecessor
                TreeNode* predecessor = cur->left;
                while (predecessor->right && predecessor->right != cur) {
                    predecessor = predecessor->right;
                }
                
                if (predecessor->right == NULL) {
                    preorder.push_back(cur->val); //push before going left
                    predecessor->right = cur;
                    cur = cur->left;
                } else {
                    predecessor->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return preorder;
    }
};                       