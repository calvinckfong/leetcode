// 3090. Maximum Length Substring With Two Occurrences
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(), res = 0;
        int freq[26] = {0};
        int l=0, r=0;

        while (r<n) {
            int i = s[r]-'a';
            r++;
            freq[i]++;
            if (freq[i]>2) {
                while (l<r && freq[i]>2) {
                    freq[s[l]-'a']--;
                    l++;
                }
            } else {
                res = max(res, r-l);
            }
        }
        return res;
    }
};
