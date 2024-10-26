// 3045. Count Prefix and Suffix Pairs II
struct TrieNode {
    bool isWord = false;
    int counter = 0;
    unordered_map<int, TrieNode*> children;
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long result = 0;

        TrieNode* root = new TrieNode();
        for (string& w: words) {
            TrieNode* node = root;
            int n = w.size();
            for (int i=0; i<n; i++) {
                int prefix_idx = w[i] - 'a';
                int suffix_idx = w[n-i-1] - 'a';
                int idx = prefix_idx * 26 + suffix_idx;
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
                result += node->counter;
            }
            node->isWord = true;
            node->counter++;
        }
        return result;
    }
};
