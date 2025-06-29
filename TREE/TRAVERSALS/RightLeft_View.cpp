//RIGHT VIEW

// class Solution {
// private:
//     void solve(TreeNode* root,vector<int> &ans,int lvl){
//         if(!root)
//             return;
//         if(lvl == ans.size()){
//             ans.push_back(root->val);
//         }
//         solve(root->right,ans,lvl+1); //pahle right ki call
//         solve(root->left,ans,lvl+1);
//     }
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int>ans;
//         solve(root,ans,0);
//         return ans;
//     }
// };

//LEFT VIEW -- Har level ki first node hi left view hogi

// class Solution {
// private:
//     void solve(TreeNode* root,vector<int> &ans,int lvl){
//         if(!root)
//             return;
//         if(lvl == ans.size()){
//             ans.push_back(root->val);
//         }
//         solve(root->left,ans,lvl+1);  //pahle left ki call
//         solve(root->right,ans,lvl+1);
//     }
// public:
//     vector<int> leftSideView(TreeNode* root) {
//         vector<int>ans;
//         solve(root,ans,0);
//         return ans;
//     }
// };