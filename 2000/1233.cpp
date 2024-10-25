// 1233. Remove Sub-Folders from the Filesystem
struct TrieNode {
    bool isEnd;
    unordered_map<string, TrieNode*> children;
    TrieNode() : isEnd(false) {}
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Construct Trie
        TrieNode* root = new TrieNode();
        for (string& f: folder) {
            TrieNode* node = root;
            stringstream ss(f);

            string token;
            while (getline(ss, token, '/')) {
                if (token.empty()) continue;
                if (node->children.find(token) == node->children.end()) {
                    node->children[token] = new TrieNode();
                }
                node = node->children[token];
            }
            node->isEnd = true;
        }

        // remove subfolder
        vector<string> result;
        for (string& f: folder) {
            TrieNode* node = root;
            stringstream ss(f);
            string token;
            bool isEnd = false;
            while (getline(ss, token, '/')) {
                if (token.empty()) continue;
                TrieNode* next = node->children[token];
                if (next->isEnd && ss.rdbuf()->in_avail()!=0) {
                    isEnd = true;
                    break;
                }
                node = next;
            }
            if (!isEnd) result.push_back(f);
        }

        delete root;
        return result;
    }
};
