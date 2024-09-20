// 214. Shortest Palindrome
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;
        int n = l.size(), j;

        vector<int> p(n, 0);
        for (int i=1; i<n; i++) {
            j = p[i-1];
            while (j>0 && l[i] != l[j])
                j = p [j-1];
            p[i] = (j += l[i]==l[j]);
        }

        return rev_s.substr(0, s.size() - p[n-1]) + s;
    }
};
