
/*
step1 : pahle root ka inorder predecessore nikalo usse right subtree ko connect krdo
step2 : fhir right pointer of root ko purani pos se todkr apn left subtree se connect kr denge.
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        //BY USING MORRIS TRAVERSAL'S LOGIC
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left){
                TreeNode* pred = curr->left;
                while(pred->right){
                    pred = pred->right;
                }
                pred->right = curr->right; //linking that pred node to curr->right
                curr->right = curr->left;

                // curr->left = NULL; // to make left part NULL
            }
            curr = curr->right;
        }
        //LEFT PARTS NULL KARNA H or just add curr->left = NULL in above steps if want in 1 pass
        curr = root;
        while(curr!=NULL){ //this is not good to make left NULLs due to 2 pass.
            curr->left = NULL;
            curr = curr->right;
        }
    }
};