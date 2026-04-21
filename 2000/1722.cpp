// 1722. Minimize Hamming Distance After Swap Operations
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for (auto& sw: allowedSwaps) {
            unite(sw[0], sw[1]);
        }

        unordered_map<int, unordered_map<int, int>> grps;
        for (int i=0; i<n; i++) {
            grps[find(i)][source[i]]++;
        }

        int res = 0;
        for (int i=0; i<n; i++) {
            int root = find(i);
            auto& freq = grps[root];
            if (freq.count(target[i]) && freq[target[i]]>0) {
                freq[target[i]]--;
            } else {
                res++;
            }
        }
        return res;
    }

private:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }
};
