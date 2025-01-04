// 1930. Unique Length-3 Palindromic Subsequences
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(), result=0;
        unordered_set<char> chars;
        for (char c: s)
            chars.insert(c);

        for (char c: chars) {
            int i, j;
            for (int k=0; k<n; k++) {
                if (s[k]==c) {
                    i=k;
                    break;
                }
            }
            for (int k=n-1; k>=0; k--) {
                if (s[k] == c) {
                    j=k;
                    break;
                }
            }

            unordered_set<char> mid;
            for (int k=i+1; k<j; k++)
                mid.insert(s[k]);
            
            result += mid.size();
        }
        
        return result;
    }
};
