// 2901. Longest Unequal Adjacent Groups Subsequence II
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1), prev(n, -1);
        int maxIdx = 0;
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (groups[i]!=groups[j] && dp[j]+1>dp[i] && valid(words[i], words[j])) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIdx])
                maxIdx = i;
        }

        vector<string> result;
        for (int i=maxIdx; i>=0; i=prev[i]) {
            result.emplace_back(words[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }

private:
    bool valid(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;

        int dist = 0;
        for (int i=0; i<s1.size(); i++) {
            dist += (s1[i] != s2[i]);
            if (dist>1) return false;
        }
        return (dist==1);
    }
};
