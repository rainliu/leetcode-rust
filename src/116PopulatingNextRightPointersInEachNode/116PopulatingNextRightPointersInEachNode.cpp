/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        return connect_helper(root, nullptr);
    }
    
    Node* connect_helper(Node* root, Node* parent) {
        if (root == nullptr) return nullptr;
        if (parent == nullptr) {
            root->next = nullptr;
        }else if (parent->right != root) {
            root->next = parent->right;
        }else if (parent->next != nullptr){
            root->next = parent->next->left;
        }
        connect_helper(root->left, root);
        connect_helper(root->right, root);
        return root;
    }
};
