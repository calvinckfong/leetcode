// 3146. Permutation Difference between Two Strings
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int result = 0;
        string::iterator it = t.begin();
        for (int i=0; i<s.size(); i++) {
            int idx = find(t.begin(), t.end(), s[i]) - it;
            result += abs(i-idx);
        }
        return result;
    }
};
