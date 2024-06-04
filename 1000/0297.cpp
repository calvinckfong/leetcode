/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 297. Serialize and Deserialize Binary Tree
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    result += to_string(node->val) + ",";
                    q.push(node->left);
                    q.push(node->right);
                }
                else
                {
                    result += "null,";
                }
            }
        }
        result.pop_back();
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root;
        stringstream ss(data);
        string t;
        queue<TreeNode**> q;
        q.push(&root);
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                TreeNode** node = q.front();
                q.pop();
                if (getline(ss, t, ',')) {
                    if (t!="null") {
                        *node = new TreeNode( atoi(t.c_str()) );
                        q.push(&((*node)->left));
                        q.push(&((*node)->right));
                    }
                }
                else
                    return root;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
