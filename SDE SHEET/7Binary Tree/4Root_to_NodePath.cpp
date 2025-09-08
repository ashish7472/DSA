class Solution {
public:
    bool getPath(TreeNode* root, vector<int>& arr, int x) {
        if (!root) {
            return false;
        }
        // Add the current node's
        // value to the path vector
        arr.push_back(root->val);
        if (root->val == x) {
            return true;
        }

        // Recursively search for the target value
        // 'x' in the left and right subtrees
        if (getPath(root->left, arr, x)
            || getPath(root->right, arr, x)) {
            return true;
        }

        // If the target value 'x' is not found
        // in the current path, backtrack
        arr.pop_back(); //backtrack
        return false;
    }

    vector<int> solve(TreeNode* A, int B) {
        vector<int> arr;

        if (A == NULL) {
            return arr;
        }
        getPath(A, arr, B);
        
        return arr;
    }
};              