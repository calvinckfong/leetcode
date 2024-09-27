// 139. Word Break
class TrieNode {
public:
    TrieNode* children[26] = {0};
    bool isWord = false;
    
    static TrieNode* buildTree(vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (string w: wordDict) {
            TrieNode* node = root;
            for (char c: w) {
                if (!node->children[c-'a'])
                    node->children[c-'a'] = new TrieNode();
                node = node->children[c-'a'];
            }
            node->isWord = true;
        }
        return root;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = TrieNode::buildTree(wordDict);
        
        int n=s.size();
        vector<bool> dp(n);
        for (int i=0; i<n; i++) {
            if (i==0 || dp[i-1]) {
                TrieNode* node = root;
                for (int j=i; j<n; j++) {
                    char c = s[j];
                    if (!node->children[c-'a'])
                        break;
                    node = node->children[c-'a'];
                    if (node->isWord) dp[j] = true;
                }
            }
        }
        return dp[n-1];
    }
};
