// 3333. Find the Original Typed String II
class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int MOD = 1e9 + 7;

        int n = word.size(), cnt=1;
        vector<int> freq;
        for (int i=1; i<n; i++) {
            if (word[i]==word[i-1]) {
                cnt++;
            } else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);

        int res=1;
        for (int f:freq) {
            res = ((long long)res * f) % MOD;
        }

        if (freq.size()>=k) return res;

        vector<int> f(k, 0), g(k, 1);
        f[0] = 1;
        for (int i=0; i<freq.size(); i++) {
            vector<int> f_new(k), g_new(k);
            for (int j=1; j<k; j++) {
                f_new[j] = g[j-1];
                int idx = j-freq[i]-1;
                if (idx >= 0) {
                    f_new[j] = (f_new[j] - g[idx] + MOD) % MOD;
                }
            }
            
            g_new[0] = f_new[0];
            for (int j=1; j<k; j++)
                g_new[j] = (g_new[j-1]+f_new[j]) % MOD;
            
            f = move(f_new);
            g = move(g_new);
        }
        return (res - g[k-1] + MOD) % MOD;
    }
};
