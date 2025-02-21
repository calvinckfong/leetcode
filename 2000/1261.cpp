// 1261. Find Elements in a Contaminated Binary Tree
class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        visited.insert(0);
        if (root->left) solve(root->left, 2*0+1);
        if (root->right) solve(root->right, 2*0+2);
    }
    
    bool find(int target) {
        return visited.count(target);
    }

private:
    unordered_set<int> visited;
    void solve(TreeNode* node, int x) {
        node->val = x;
        visited.insert(x);
        if (node->left) solve(node->left, 2*x+1);
        if (node->right) solve(node->right, 2*x+2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
