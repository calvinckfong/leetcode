// 2458. Height of Binary Tree After Subtree Removal Queries
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        heights.clear();

        // Gather the solutions for all nodes
        dfs(root, 0, 0);

        int k = queries.size();
        vector<int> result(k);
        for (int i=0; i<k; i++) {
            result[i] = resultMap[queries[i]];
        }
        return result;
    }

private:
    int resultMap[100001];
    unordered_map<TreeNode*, int> heights;
    void dfs(TreeNode* node, int h, int maxHeight) {
        resultMap[node->val] = maxHeight;

        if (node->left) {
            int maxHeightRight = max(maxHeight, h+1+getHeight(node->right));
            dfs(node->left,  h+1, maxHeightRight);
        }
        if (node->right) {
            int maxHeightLeft  = max(maxHeight, h+1+getHeight(node->left));
            dfs(node->right, h+1, maxHeightLeft);
        }
    }

    int getHeight(TreeNode* node) {
        if (!node) return -1;
        if (heights.count(node) == 0) {    
            int h = 1 + max(getHeight(node->left), getHeight(node->right));
            heights[node] = h;
        }
        return heights[node];
    }
};
