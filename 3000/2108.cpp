// 2108. Find First Palindromic String in the Array
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int l=0, r=n-1;
        while (r>l)
        {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for (int i=0; i<words.size(); i++)
            if (isPalindrome(words[i]))
                return words[i];
        return "";
    }
};
