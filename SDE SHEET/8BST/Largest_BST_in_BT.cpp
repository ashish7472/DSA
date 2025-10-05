class NodeValue {
public:
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0); //{minimal, maximal, size_of_BST}

        // Get values from left and right subtree
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        //Now Postorder traversal is done ab ye karo
        // Current node is greater than max in left and smaller than min in right
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a Valid BST
            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        // Otherwise return [-inf, inf] so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public: //starting
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};