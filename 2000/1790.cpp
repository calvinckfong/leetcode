// 1790. Check if One String Swap Can Make Strings Equal
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), diff=0;
        int freq1[26], freq2[26];
        for (int i=0; i<n; i++) {
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
            diff += (s1[i]!=s2[i]);
        }

        for (int i=0; i<26; i++)
            if (freq1[i] != freq2[i]) return false;

        return diff==2 || diff==0;
    }
};
