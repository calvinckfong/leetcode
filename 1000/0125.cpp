// 125. Valid Palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l=0, r=n-1;
        char cl, cr;

        while (l<r)
        {
            cl=0; cr=0;
            if (!isalnum(s[l]))
            {
                l++;
                continue;
            }

            if (!isalnum(s[r]))
            {
                r--;
                continue;
            }

            if (tolower(s[l]) != tolower(s[r])) return false;
            l++; r--;

        }
        return true;
    }
};
