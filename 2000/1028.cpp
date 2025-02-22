// 1028. Recover a Tree From Preorder Traversal
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> stk;
        int n = traversal.size(), i = 0;

        while (i<n) {
            int depth = 0, value = 0;
            while (i<n && traversal[i]=='-') {
                depth++;
                i++;
            }
            while (i<n && isdigit(traversal[i])) {
                value = value*10 + (traversal[i]-'0');
                i++;
            }

            TreeNode* node = new TreeNode(value);

            while (stk.size() > depth) {
                stk.pop();
            }

            if (!stk.empty()) {
                if (stk.top()->left) {
                    stk.top()->right = node;
                } else {
                    stk.top()->left = node;
                }
            }

            stk.push(node);
        }

        while (stk.size()>1) {
            stk.pop();
        }

        return stk.top();
    }
};
