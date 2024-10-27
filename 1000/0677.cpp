// 677. Map Sum Pairs
struct TrieNode {
    int val = 0;
    TrieNode* children[26] = {0};
};

class MapSum {
public:
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* node = root;
        for (char c: key) {
            if (!node->children[c-'a'])
                node->children[c-'a'] = new TrieNode();
            node = node->children[c-'a'];
        }
        node->val = val;
    }
    
    int sum(string prefix) {
        TrieNode* node = root;
        for (char c: prefix) {
            if (node->children[c-'a'])
                node = node->children[c-'a'];
            else
                return 0;
        }
        return sumNode(node);
    }

private:
    TrieNode* root;

    int sumNode(TrieNode* node) {
        if (!node) return 0;
        int sum = node->val;
        for (int i=0; i<26; i++) {
            sum += sumNode(node->children[i]);
        }
        return sum;
    }
};
