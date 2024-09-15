// 1371. Find the Longest Substring Containing Vowels in Even Counts
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        char bitmask[26] = {0};
        bitmask['a' - 'a'] = 1;
        bitmask['e' - 'a'] = 2;
        bitmask['i' - 'a'] = 4;
        bitmask['o' - 'a'] = 8;
        bitmask['u' - 'a'] = 16;

        vector<int> mp(32, -1);
        char xorSum=0;
        int result=0;
        for (int i=0; i<n; i++) {
            xorSum ^= bitmask[s[i]-'a'];
            if (mp[xorSum]==-1 && xorSum!=0) mp[xorSum] = i;
            result = max(result, i-mp[xorSum]);
        }
        return result;
    }
};
