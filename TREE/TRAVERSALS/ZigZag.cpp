class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)
            return res;

        queue<TreeNode*>q;
        q.push(root);

        bool LtoR = true;

        while(!q.empty()){
            int n = q.size();
            vector<int>ans(n);

            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();

                int index = LtoR ? i : n-i-1;
                ans[index] = temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            LtoR = !LtoR;

            res.push_back(ans);
        }
        return res;
    }
};