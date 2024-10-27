// 421. Maximum XOR of Two Numbers in an Array
struct TrieNode {
    TrieNode* children[2] = {0};
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // Building Trie-tree
        TrieNode* root = new TrieNode();
        for (int num: nums) {
            TrieNode* node = root;
            for (int b=30; b>=0; b--) {
                int idx = (num>>b)&1;
                if (!node->children[idx])
                    node->children[idx] = new TrieNode();

                node = node->children[idx];
            }
        }

        // search for max-xor
        int maxVal = 0;
        for (int num: nums) {
            TrieNode* node = root;
            int val=0;
            for (int b=30; b>=0; b--) {
                int idx = (num>>b)&1;
                if (node->children[1-idx]) {
                    val += (1 << b);
                    node = node->children[1-idx];
                } else {
                    node = node->children[idx];
                }
            }
            maxVal = max(maxVal, val);
        }
        
        return maxVal;
    }
};
