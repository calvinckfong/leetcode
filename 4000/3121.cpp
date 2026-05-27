// 3121. Count the Number of Special Characters II

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int lpos[26], upos[26];
        int res = 0, k;

        for (int i=0; i<26; i++) {
            lpos[i] = -1;
            upos[i] = 200000;
        }

        for (int i=0; i<n; i++) {
            char& c = word[i];
            if (c>='a') {
                k = c-'a';
                lpos[k] = max(lpos[k], i);
            } else {
                k = c-'A';
                upos[k] = min(upos[k], i);
            }
        }

        for (int i=0; i<26; i++) {
            if (lpos[i]>=0 && upos[i]<200000)
            {
                res += (upos[i] > lpos[i]);
            }
        }

        return res;
    }
};
