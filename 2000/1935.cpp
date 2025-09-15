// 1935. Maximum Number of Words You Can Type
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int broken[26] = {0};
        for (char c: brokenLetters) {
            broken[c-'a'] = 1;
        }

        int res = 0,  bad = 0;
        for (char c: text) {
            if (c == ' ') {
                if (bad == 0) res++;
                bad = 0;
            } else if (broken[c-'a']) {
                bad = 1;
            }
        }
        if (!bad) res++;
        return res;
    }
};
