// 2416. Sum of Prefix Scores of Strings
class TrieNode {
public:
    TrieNode* children[26];
    int count;

    static TrieNode* buildTree(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w: words) {
            TrieNode* node = root;
            for (char c: w) {
                if (node->children[c-'a']==nullptr)
                    node->children[c-'a'] = new TrieNode();
                node = node->children[c-'a'];
                node->count++;
            }
        }
        return root;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> result(n);
        TrieNode* root = TrieNode::buildTree(words);

        for (int i=0; i<n; i++) {
            string w = words[i];
            int sum = 0;
            TrieNode* node = root;

            for (char c: w) {
                if (node->children[c-'a'] == nullptr) break;
                
                node = node->children[c-'a'];
                sum += node->count;
            }
            result[i] = sum;
        }

        return result;
    }
};
