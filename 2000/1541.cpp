// 1541. Minimum Insertions to Balance a Parentheses String
class Solution {
public:
    int minInsertions(string s) {
        int len = s.size();
        int l = 0, res = 0;
        for (int i=0; i<len; i++) {
            char c = s[i];
            if (c == '(') {
                l++;
            } else {
                if (l>0) l--;
                else res++;

                if (i<len-1 && s[i+1]==')') i++;
                else res++;
            }
        }
        res += l*2;
        return res;
    }
};
