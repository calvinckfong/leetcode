// 1400. Construct K Palindrome Strings
class Solution {
public:
    bool canConstruct(string s, int k) {
        int freq[26], oddCnt=0;
        if (s.size()<k) return false;

        for (char c: s) {
            freq[c-'a']++;
        }
        for (int i=0; i<26; i++) {
            oddCnt += (freq[i] % 2);
        }
        if (oddCnt>k) return false;

        return true;
    }
};
