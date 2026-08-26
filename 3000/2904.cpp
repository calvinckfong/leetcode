// 2904. Shortest and Lexicographically Smallest Beautiful String
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if (ranges::count(s, '1')<k) return "";

        string res = s;
        int n = 0;
        for (int l=0, r=0; r<s.size(); r++) {
            n += s[r] - '0';
            while (n>k || s[l]=='0') {
                n -= s[l]-'0';
                l++;
            }
            if (n==k) {
                string t = s.substr(l, r-l+1);
                if (t.size()<res.size() ||
                    t.size()==res.size() && t<res) {
                    res = move(t);
                } 
            }
        }
        return res;
    }
};
