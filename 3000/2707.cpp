// 2707. Extra Characters in a String
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word;

    static TrieNode* buildTrie(vector<string>& dict) {
        TrieNode* root = new TrieNode();
        for (string& word: dict) {
            TrieNode* node = root;
            for (char c: word) {
                if (node->children.find(c) == node->children.end()) 
                    node->children[c] = new TrieNode();
                node = node->children[c];
            }
            node->is_word = true;
        }
        return root;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        len = s.size();
        root = TrieNode::buildTrie(dictionary);
        return solve(s, 0);
    }

private:
    int len;
    TrieNode* root;
    unordered_map<int, int> dp;

    int solve(string& s, int start) {
        if (start == len) return 0;
        if (dp.count(start)) return dp[start];

        int result = solve(s, start+1) + 1;
        TrieNode *node = root;
        for (int i=start; i<len; i++) {
            char c = s[i];
            if (node->children.find(c) == node->children.end())
                break;
            node = node->children[c];
            if (node->is_word)
                result = min(result, solve(s, i+1));
        }
        return dp[start] = result;
    }
};
