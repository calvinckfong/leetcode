// 140. Word Break II
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> str_set(wordDict.begin(), wordDict.end());
        vector<string> result, intermediate;

        solve(s, result, str_set, intermediate);
        return result;
    }

private:
    void solve(string s, vector<string>& result, unordered_set<string>& str_set, vector<string>& intermediate) {
        if (s.size() == 0) {
            string res;
            for (string i: intermediate) res += i + " ";
            res.pop_back(); // remove last space
            result.push_back(res); // append to result set
        }

        // backtracing
        for (int i=0; i<s.size(); i++) {
            // check if sub-string in str_set
            string substr = s.substr(0, i+1);
            if (str_set.count(substr)) {
                intermediate.push_back(substr);
                solve(s.substr(i+1), result, str_set, intermediate);
                intermediate.pop_back();
            }
        }
    }
};
