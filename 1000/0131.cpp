// 131. Palindrome Partitioning
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> parts;

        partition(s, 0, parts, result);
        
        return result;
    }

    void partition(string& s, int start, vector<string>& parts, vector<vector<string>>& result) {
        int n = s.size();
        if (n == start)
            result.push_back(parts);
        else {
            for (int i=start; i<n; i++) {
                if (isPalindrome(s, start, i)) {
                    parts.push_back(s.substr(start, i-start+1));
                    partition(s, i+1, parts, result);
                    parts.pop_back();
                }
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l<r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
