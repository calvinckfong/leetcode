// 387. First Unique Character in a String
class Solution {
public:
    int firstUniqChar(string s) {
        int i, n = s.length();
        int freq[26] = {0};
        for (i=0; i<n; i++)
            freq[s[i]-'a']++;

        for (i=0; i<n; i++)
        {
            if (freq[s[i]-'a'] == 1)
                return i;
        }
        
        return -1;
    }
};
