// FLOOR - LARGEST NODE <= KEY

int floor InBST(TreeNode << int > *root, int key)
{
    int floor = -1;
    while (root)
    {
        if (root->val == key)
        {
            floor = root->val;
            return floor;
        }
        if (root->val < key)
        {
            floor = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
}

// CEIL - LARGEST NODE >= KEY

int ceil InBST(TreeNode << int > *root, int key)
{
    int ceil = -1;
    while (root)
    {
        if (root->val == key)
        {
            ceil = root->val;
            return ceil;
        }
        if (root->val > key)
        {
            ceil = root->val;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ceil;
}