// 208. Implement Trie (Prefix Tree)
class TrieNode {
public:
    char val;
    TrieNode* children[26];
    bool isEnd;

    TrieNode() : val(0), isEnd(false) {
        for (int i=0; i<26; i++)    children[i] = nullptr;
    }

    TrieNode(char c) : val(c), isEnd(false) {
        for (int i=0; i<26; i++)    children[i] = nullptr;
    }

    TrieNode(char c, bool b) : val(c), isEnd(b) {
        for (int i=0; i<26; i++)    children[i] = nullptr;
        isEnd = false;
    }

    ~TrieNode() {
        for (int i=0; i<26; i++) {
            if (children[i])
                delete children[i];
        }    
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for (int i=0; i<word.size(); i++)
        {
            int key = word[i]-'a';
            if (p->children[key]==nullptr)
                p->children[key] = new TrieNode(word[i]);
            p = p->children[key];
            if (i==word.size()-1)
                p->isEnd = true;
        }
    }
    
    bool search(string word) {
        TrieNode* p = root;
        for (int i=0; i<word.size(); i++)
        {
            char key = word[i] - 'a';
            if (p->children[key]==nullptr) return false;
            p = p->children[key];
        }
        return (p->isEnd);
    }
    
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (int i=0; i<prefix.size(); i++)
        {
            char key = prefix[i] - 'a';
            if (p->children[key]==nullptr) return false;
            p = p->children[key];
        }
        return true;       
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
