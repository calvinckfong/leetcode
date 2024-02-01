// 3. Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0, r=0; // left and right pointers
        int maxLen = 0;
        vector<int> cnt(128);

        for (r=0; r<n; r++)
        {
            // increment counter for character right pointer  
            ++cnt[s[r]];
            // shrink left pointer if repeat character
            while (cnt[s[r]]>1)
            {
                --cnt[s[l++]];
            }
            // keep max window size
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};
