// 5. Longest Palindromic Substring
class Solution {
public:
    int Palindrome(string s, int& l, int& r)
    {
        int n = s.size(), maxlen = -1;
        while (l>=0 && r<n)
        {
            if (s[l] == s[r]) {
                maxlen = r-l+1;
                l--; r++;
            }
            else break;
        }
        return maxlen;
    }

    string longestPalindrome(string s) {
        int n=s.size(), l, r, len;
        int best_l=0, maxlen=0;
        for (int i=0; i<n; i++)
        {
            l=r=i;
            len = Palindrome(s, l, r);
            if (len > maxlen)
            {
                maxlen = len;
                best_l = l+1;
            }
            l=i; r=i+1;
            len = Palindrome(s, l, r);
            if (len > maxlen)
            {
                maxlen = len;
                best_l = l+1;
            }
        }
        return s.substr(best_l, maxlen);
    }
};
