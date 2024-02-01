// 392. Is Subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos, start=0;
        for (int i=0; i<s.size(); i++)
        {
            pos = t.find(s[i], start);
            if (pos == -1)
                return false;
            start = pos+1;
        }
        return true;
    }
};
