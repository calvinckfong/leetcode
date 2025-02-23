// 889. Construct Binary Tree from Preorder and Postorder Traversal
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return construct(preorder, postorder);
    }

private:
    int preIndex=0, postIndex=0;
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* node = new TreeNode(preorder[preIndex++]);
        
        if (node->val != postorder[postIndex]) {
            node->left = construct(preorder, postorder);
        }

        if (node->val != postorder[postIndex]) {
            node->right = construct(preorder, postorder);
        }

        postIndex++;
        return node;
    }
};
