class Solution {
public:
    // Function to find the diameter of a binary tree
    int diameterOfBinaryTree(Node* root) {
        int diameter = 0;

        height(root, diameter);
        return diameter;
    }

private:
    // Function to calculate the height of the tree and update the diameter
    int height(Node* node, int& diameter) {
        if (!node) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};