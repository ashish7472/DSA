vector<vector<int>> preInPostTraversal(Node* root) {
    vector<int> pre, in, post;
    if (root == NULL) {
        return {};
    }
    // Stack to maintain nodes
    // and their traversal state
    stack<pair<Node*, int>> st;

    // Start with the root node
    // and state 1 (preorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of pre
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second = 2;
            st.push(it); 

            // Push left child onto stack
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }

        // this is a part of in
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second = 3;
            st.push(it); 

            // Push right child onto stack
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }

        // this is part of post
        else {
            post.push_back(it.first->data);
        }
    }

    // Returning the traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}