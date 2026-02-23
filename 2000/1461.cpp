// 1461. Check If a String Contains All Binary Codes of Size K
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n<k) return false;
        unordered_set<string> uset;

        for (int i=0; i<=n-k; i++) {
            string ss = s.substr(i, k);
            uset.insert(ss);
        }

        return uset.size() == (1<<k);
    }
};
