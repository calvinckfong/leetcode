// 1160. Find Words That Can Be Formed by Characters
class Solution {
public:
    bool canBuild(int s_cnt[], int char_cnt[])
    {
        for (int i=0; i<26; i++)
            if (s_cnt[i] > char_cnt[i]) return false;
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        int result = 0;
        int char_cnt[26];
        for (char c: chars) char_cnt[c-'a']++;

        for (string s: words)
        {
            int s_cnt[26] = {0};
            for (char c: s) s_cnt[c-'a']++;

            if (canBuild(s_cnt, char_cnt)) result += s.size();
        }

        return result;
    }
};
