class Solution{
    private:    
        int dfsHeight(TreeNode* root){
            if(!root) return 0;

            int lt = dfsHeight(root->left);
            int rt = dfsHeight(root->right);

            if(abs(lt-rt)>1) return -1;
            if(lt ==-1 || rt == -1) return -1; //agar lt/rt koi bhi -1 return kr rha h to aage bs -1 hi return hoga

            return max(lt,rt)+1; //agar balaced tree h to normal ht return karo
        }
    public:
        bool isBalanced(TreeNode* root){
            return dfsHeight(root) != -1;
        }
};