#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

vector<int> iterativeInorder(Node* root) {
    vector<int> result;
    stack<Node*> st;
    Node* curr = root;

    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        result.push_back(curr->data);
        curr = curr->right;
    }
    return result;
}

vector<int> iterativePreorder(Node* root) {
    vector<int> result;
    if (!root) return result;
    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* node = st.top();
        st.pop();
        result.push_back(node->data);

        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return result;
}

vector<int> iterativePostorder(Node* root) {
    vector<int> result;
    if (!root) return result;
    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* node = st1.top();
        st1.pop();
        st2.push(node);

        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }

    while (!st2.empty()) {
        result.push_back(st2.top()->data);
        st2.pop();
    }
    return result;
}