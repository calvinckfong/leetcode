// 1593. Split a String Into the Max Number of Unique Substrings
class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> tokens;
        int result = 0;
        solve(s, tokens, 0, 0, result);
        return result;
    }

private:
    void solve(string& s, unordered_set<string>& tokens, int start, int count, int& maxCount) {
        // total combinations less than maxCount
        if (maxCount > s.size()-start + count) return;

        // end of string
        if (start == s.size()) {
            maxCount = max(maxCount, count);
            return;
        }

        // extract possible substrings
        for (int end=start+1; end<=s.size(); end++) {
            string ss = s.substr(start, end-start);
            if (tokens.find(ss) == tokens.end()) {
                tokens.insert(ss);
                solve(s, tokens, end, count+1, maxCount);
                tokens.erase(ss);
            }
        }
    }
};
