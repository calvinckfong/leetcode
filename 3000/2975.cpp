// 2975. Maximum Square Area by Removing Fences From a Field
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;
        unordered_set<int> hEdges = getEdges(hFences, m);
        unordered_set<int> vEdges = getEdges(vFences, n);

        int res = 0;
        for (auto& e: hEdges) {
            if (vEdges.contains(e))
                res = max(res, e);
        }

        if (res==0) return -1;
        return (1LL * res * res) % MOD;
    }

private:
    unordered_set<int> getEdges(vector<int>& fences, int border) {
        unordered_set<int> res;
        fences.push_back(1);
        fences.push_back(border);
        sort(fences.begin(), fences.end());
        int n = fences.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                res.insert(fences[j]-fences[i]);
            }
        }
        return res;
    }
};
