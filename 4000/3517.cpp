// 3517. Smallest Palindromic Rearrangement I
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size(), cnt[26] = {0};
        for (int i=0; i<n/2; i++) {
            cnt[s[i]-'a']++;
        }

        int l=0, r = s.size()-1;
        for (int i=0; i<26; i++) {
            while (cnt[i] > 0) {
                char c = 'a' + i;
                s[l++] = c;
                s[r--] = c;
                cnt[i]--;
            }
        }

        return s;
    }
};
