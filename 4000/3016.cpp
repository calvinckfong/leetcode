// 3016. Minimum Number of Pushes to Type Word II
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c: word) {
            freq[c-'a']++;
        }

        sort(freq.rbegin(), freq.rend());
        int result=0, key=1, i=0;
        while (i<26)
        {
            for (int j=0; j<8; j++)
            {
                result += key*freq[i++];
                if (i>=26) return result;
            }
            key++;
        }
        return result;
    }
};
