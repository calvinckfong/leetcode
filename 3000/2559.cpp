// 2559. Count Vowel Strings in Ranges
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> cnt(n+1);
        for (int i=0; i<n; i++) {
            cnt[i+1] = cnt[i];
            int l = words[i].size();
            cnt[i+1] += (IsVowel(words[i][0]) && IsVowel(words[i][l-1]));
        }

        int nq = queries.size();
        vector<int> result(nq);
        for (int i=0; i<nq; i++) {
            result[i] = cnt[queries[i][1]+1] - cnt[queries[i][0]];
        }
        return result;
    }

private:
    bool IsVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
};
