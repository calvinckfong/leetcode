// 2486. Append Characters to String to Make Subsequence
class Solution {
public:
    int appendCharacters(string s, string t) {
        int ns=s.size(), nt=t.size(), i=0, j=0;
        while (i<ns && j<nt) {
            if (s[i++] == t[j]) j++;
        }
        return nt-j;
    }
};
