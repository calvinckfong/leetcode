// 2472. Maximum Number of Non-overlapping Palindrome Substrings
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int res = 0, start = 0;

        for (int r=k-1; r<n; r++) {
            int l = r - k + 1;
            if (l>=start && check(s, l, r)) {
                res++;
                start = r + 1;
                continue;
            }

            l = r - k;
            if (l>=start && check(s, l, r)) {
                res++;
                start = r + 1; 
            }
        }
        return res;
    }

private:
    bool check(string& s, int l, int r) {
        while (l<r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
