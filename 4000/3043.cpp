// 3043. Find the Length of the Longest Common Prefix
class TrieNode {
public:
    // unordered_map<char, TrieNode*> children;
    TrieNode* children[10] = {nullptr};

    static void buildTree(TrieNode* root, vector<int>& arr1) {
        for (int val: arr1) {
            string s = to_string(val);
            TrieNode* node = root;
            for (char c: s) {
                if (node->children[c-'0'] == nullptr)
                    node->children[c-'0'] = new TrieNode();
                node = node->children[c-'0'];
            }
        }
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();
        TrieNode::buildTree(root, arr1);

        int result = 0;
        for (int val: arr2) {
            result = max(result, commonPrefixLen(root, val));
        }
        return result;
    }

private:
    int commonPrefixLen(TrieNode* root, int val) {
        string s = to_string(val);
        int result = 0;
        TrieNode* node = root;
        for (char c: s) {
            if (node->children[c-'0'] == nullptr) break;
            node = node->children[c-'0'];
            result++;
        }
        return result;
    }
};
