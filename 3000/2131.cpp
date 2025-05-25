// 2131. Longest Palindrome by Concatenating Two Letter Words
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int unpaired = 0;
        int result = 0;
        for (string& s: words) {
            if (s[0] == s[1]) {
                if (freq[s]>0) {
                    unpaired--;
                    result += 4; 
                    freq[s]--;
                }
                else
                {
                    unpaired++;
                    freq[s]++;
                }
            } else {
                string rev = s;
                reverse(rev.begin(), rev.end());
                if (freq[rev] > 0) {
                    result += 4;
                    freq[rev]--;
                } else {
                    freq[s]++;
                }
            }
        }
        return result + 2*(unpaired>0);
    }
};
