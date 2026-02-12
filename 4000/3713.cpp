// 3713. Longest Balanced Substring I
class Solution {
public:
    int longestBalanced(string s) {
        int res = 0, n=s.size();

        for (int i=0; i<n && n-i>res; i++) {
            int freq[26] = {0};
            int len = 1, maxf=0, dist = 0;
            for (int j=i; j<n; j++, len++) {
                int k = s[j] - 'a';
                dist += (freq[k] == 0);
                maxf = max(maxf, ++freq[k]);

                if (len == dist*maxf)
                    res = max(res, len);
            }
        }
        return res;
    }
};
