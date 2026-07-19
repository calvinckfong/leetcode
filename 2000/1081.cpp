// 1081. Smallest Subsequence of Distinct Characters
class Solution {
public:
    string smallestSubsequence(string s) {
        int freq[26] = {0}, vis[26] = {0};
        int n = s.size();
        for (auto&c: s) {
            freq[c-'a']++;
        }

        string res;
        for (auto& c: s) {
            if (!vis[c-'a']) {
                while (!res.empty() && res.back()>c) {
                    int last = res.back() - 'a';
                    if (freq[last]>0) {
                        vis[last] = 0;
                        res.pop_back();
                    } else {
                        break;
                    }
                }
                vis[c-'a'] = 1;
                res.push_back(c);
            }
            freq[c-'a']--;
        }
        return res;
    }
};
