// 1255. Maximum Score Words Formed by Letters
class Solution {
public:
    int freq[26]={0}, cnt[26]={0};
    int result=0;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (char c: letters) freq[c-'a']++;
        solve(0, words, score);
        return result;
    }

private:
    void solve(int idx, vector<string>& words, vector<int>& score) {
        if (idx == words.size()) {
            int s = 0;
            for (int i=0; i<26; i++) {
                if (cnt[i]>freq[i]) return;
                s += score[i] * cnt[i];
            }
            result = max(result, s);
            return;
        }

        solve(idx+1, words, score);
        for (char c: words[idx]) cnt[c-'a']++;
        solve(idx+1, words, score);
        for (char c: words[idx]) cnt[c-'a']--;
    }
};
