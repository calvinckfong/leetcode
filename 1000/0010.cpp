// 10. Regular Expression Matching
class Solution {
public:
    bool isMatch(string s, string p) {
        s_len = s.size();
        p_len = p.size(); 
        dp = vector<vector<char>>(s_len+1, vector<char>(p_len+1, -1));
        return solve(0, 0, s, p);
    }

private:
    int s_len, p_len;
    vector<vector<char>> dp;

    bool solve(int i, int j, string& s, string& p) {
        if (dp[i][j] != -1) return dp[i][j];

        bool result;
        if (j == p_len)
            result = (i == s_len);
        else {
            bool first_match = (i<s_len && (
                p[j]==s[i] || p[j]=='.'));

            if (j+1<p_len && p[j+1]=='*')
                result = solve(i, j+2, s, p) || 
                        (first_match && solve(i+1, j, s, p));
            else
                result = first_match && solve(i+1, j+1, s, p);
        }
        return dp[i][j] = result;
    }
};
