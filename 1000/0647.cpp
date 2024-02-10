// 647. Palindromic Substrings
class Solution {
public:
    int Palindromic(string s, int l, int r) {
        int n = s.length();
        int cnt=0;
        while (l>=0 && r<n && s[l--]==s[r++])
        {
            cnt++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int n=s.length();
        int result = 0;
        for (int i=0; i<n; i++)
        {
            result += Palindromic(s, i, i);
            result += Palindromic(s, i, i+1);
        }

        return result;
    }
};
