// 2516. Take K of Each Character From Left and Right
class Solution {
public:
    int takeCharacters(string s, int k) {
        int freq[3] = {0};
        for (char c: s) {
            freq[c-'a']++;
        }
        if (freq[0]<k || freq[1]<k || freq[2]<k) return -1;

        int n=s.size(), l=0, r, maxWin=0;
        int window[3] = {0};
        for (r=0; r<n; r++) {
            window[s[r]-'a']++;

            while (l<=r) {
                if (freq[0]-window[0]>=k && freq[1]-window[1]>=k && freq[2]-window[2]>=k) break;
                window[s[l]-'a']--;
                l++;
            }

            maxWin = max(maxWin, r-l+1);
        }
        return n-maxWin;
    }
};
