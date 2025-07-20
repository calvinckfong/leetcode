// 1948. Delete Duplicate Folders in System

struct Trie {
    string serial;
    unordered_map<string, Trie*> children;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {

        Trie* root = new Trie();
        for (const vector<string>& path: paths) {
            Trie* curr = root;
            for (const string& node: path) {
                if (!curr->children.count(node)) {
                    curr->children[node] = new Trie();
                }
                curr = curr->children[node];
            }
        }

        create(root);

        vector<vector<string>> res;
        vector<string> path;
        
        function<void(Trie*)> operate = [&](Trie* node) {
            if (freq[node->serial] > 1) return;

            if (!path.empty())
                res.push_back(path);

            for (auto& [folder, child]: node->children) {
                path.push_back(folder);
                operate(child);
                path.pop_back();
            }
        };

        operate(root);
        return res;
    }

private:
    unordered_map<string, int> freq;
    
    void create(Trie* node) {
        if (node->children.empty()) return;

        vector<string> tmp;
        for (auto& [folder, child]: node->children) {
            create(child);
            tmp.push_back(folder + "(" + child->serial + ")");
        }

        sort(tmp.begin(), tmp.end());
        for (string& s: tmp) {
            node->serial += move(s);
        }

        freq[node->serial]++;
    }
};
