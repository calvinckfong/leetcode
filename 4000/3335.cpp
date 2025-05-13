// 3335. Total Characters in String After Transformations I
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        int cnt[26] = {0};
        for (auto& c: s) {
            cnt[c-'a']++;
        }

        while (t > 0) {
            int tmp0 = cnt[25];
            int tmp1 = (cnt[0] + cnt[25]) % MOD;
            for (int i=25; i>=2; i--)
                cnt[i] = cnt[i-1];
            cnt[0] = tmp0;
            cnt[1] = tmp1;
            t--;
        }

        int result = 0;
        for (int i=0; i<26; i++) {
            result = (result + cnt[i]) % MOD;
        }
        return result;
    }
};
