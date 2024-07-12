// 1717. Maximum Score From Removing Substrings
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string pattern1="ab", pattern2="ba";
        if (y>x) {
            swap(pattern1, pattern2);
            swap(x, y);
        }
        return solve(s, pattern1, x) + solve(s, pattern2, y);
    }

private:
    int solve(string& s, string p, int x) {
        int result=0, pos=1;
        for (int i=1; i<s.size(); i++) {
            s[pos] = s[i];
            if (pos>0 && s[pos-1]==p[0] && s[pos]==p[1]) {
                result += x;
                pos--;
            } else pos++;
        }
        s.resize(pos);
        return result;
    }
};
