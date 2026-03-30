// 2840. Check if Strings Can be Made Equal With Operations II
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int freq[2][26] = {0};
        int n = s1.size();
        for (int i=0; i<n; i++) {
            int isOdd = i&1;
            freq[isOdd][s1[i]-'a']++;
            freq[isOdd][s2[i]-'a']--;
        }
        for (int i=0; i<26; i++) {
            if (freq[0][i] || freq[1][i]) return false;
        }
        return true;
    }
};
