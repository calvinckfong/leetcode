/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// 590. N-ary Tree Postorder Traversal
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        solve(root, result);
        return result;
    }

private:
    void solve(Node* node, vector<int>& result) {
        if (node == nullptr) return;
        
        for (Node* n: node->children) {
            solve(n, result);
        }

        result.push_back(node->val);
    }
};
