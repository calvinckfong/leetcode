// 409. Longest Palindrome
class Solution {
public:
    int longestPalindrome(string s) {
        if (s.size()==1) return 1;

        vector<int> freq(26+32, 0);
        for (const char c: s) {
            freq[c-'A']++;
        }
        sort(freq.rbegin(), freq.rend());

        int result=0, odd=0;
        for (int i=0; i<26+32; i++) {
            if (freq[i] == 0) break;
            if (!odd) {
                result += freq[i];
                if (freq[i]%2) odd = 1;
            } else {
                result += freq[i] - (freq[i]%2);
            }
        }
        return result;
    }
};
