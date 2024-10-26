// 211. Design Add and Search Words Data Structure
struct TrieNode {
    bool isWord;
    TrieNode* children[26] = {0};
    TrieNode() : isWord(false) {}
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (int i=0; i<word.size(); i++) {
            int idx = word[i]-'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return searchNode(node, word, 0);
    }

private:
    TrieNode* root;

    bool searchNode(TrieNode* node, string& w, int idx) {
        if (idx >= w.size()) return node->isWord;

        if (w[idx] == '.') {
            for (int i=0; i<26; i++) {
                if (node->children[i]) {
                    if (searchNode(node->children[i], w, idx+1))
                        return true;
                }
            }
        } else {
            int i = w[idx]-'a';
            if (!node->children[i]) return false;
            return searchNode(node->children[i], w, idx+1);
        }
        return false;
    }
};
