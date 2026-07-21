// 3499. Maximize Active Section with Trade I
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');

        vector<int> zeroBlocks;
        int i = 0;
        while (i<n) {
            int start = i;
            while (i<n && s[i]==s[start]) i++;

            if (s[start]=='0') {
                zeroBlocks.push_back(i-start);
            }
        }

        int m = zeroBlocks.size();
        if (m<2) return ones;

        int gain = 0;
        for (int i=0; i<m-1; i++) {
            gain = max(gain, zeroBlocks[i] + zeroBlocks[i+1]);
        }
        return ones + gain;
    }
};
