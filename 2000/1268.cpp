// 1268. Search Suggestions System
class Trie {
public:
    Trie() { 
        root = new TrieNode();
    }

    void add(string name) {
        curr = root;
        for (char& c: name) {
            if (curr->children[c-'a']==nullptr)
                curr->children[c-'a'] = new TrieNode();
            curr = curr->children[c-'a'];
        }
        curr->isWord = true;
    }

    vector<string> search(string name) {
        vector<string> result;
        curr = root;
        for (char& c:name) {
            if (curr->children[c-'a']==nullptr) return result;
            curr = curr->children[c-'a'];
        }
        getLeafNodes(curr, name, result);
        return result;
    }

private:
    struct TrieNode {
        bool isWord = false;
        vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    } *root, *curr;

    void getLeafNodes(TrieNode* curr, string& prefix, vector<string>& result) {
        if (result.size()==3) return;
        if (curr->isWord) result.push_back(prefix);

        for (int i=0; i<26; i++) {
            if (curr->children[i]) {
                prefix+=('a'+i);
                getLeafNodes(curr->children[i], prefix, result);
                prefix.pop_back();
            }
        }

    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // Construct trie
        Trie trie;
        for (string& name: products)
            trie.add(name);

        // search
        vector<vector<string>> result;
        string prefix;
        for (char c: searchWord) {
            prefix += c;
            result.push_back(trie.search(prefix));
        }
        return result;
    }
};
