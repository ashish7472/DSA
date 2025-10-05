//width is dependent on level so we'll use bfs
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = 0;

        //Queue of TreeNode* and its position in the level
        queue<pair<TreeNode*, int>> q; //{node,index}
        q.push({root, 0});

        while (!q.empty()) {
            // nodes at the current level
            int size = q.size();

            int mmin = q.front().second; //minimum index at this lvl
            
            // Store the first and last positions of nodes in the current level
            int first, last;

            for (int i = 0; i < size; i++) {
                // Calculate current position relative to the minimum position in the level
                int cur_id = q.front().second - mmin;
                // Get the current node
                TreeNode* node = q.front().first;
                // Pop the front node from the queue
                q.pop();

                // If this is the first node in the level, update the 'first' variable
                if (i == 0) {
                    first = cur_id;
                }

                // If this is the last node in the level, update the 'last' variable
                if (i == size - 1) {
                    last = cur_id;
                }

                // Enqueue the left child of the current node with its position
                if (node->left) {
                    q.push({node->left, cur_id * 2 + 1});
                }

                // Enqueue the right child of the current node with its position
                if (node->right) {
                    q.push({node->right, cur_id * 2 + 2});
                }
            }

            // Update the maximum width by calculating the difference between the first and last positions, and adding 1
            ans = max(ans, last - first + 1);
        }

        // Return the maximum width of the binary tree
        return ans;
    }
};
