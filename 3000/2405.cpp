// 2405. Optimal Partition of String
class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        int result = 1; // at least 1 char, so at least 1 substring
        int bitMask=0; // using bitMask to check any repeated char
        
        for (int i=0; i<n; i++)
        {
            if (bitMask & 1<<(s[i]-'a'))
            {
                // Repeat char found
                bitMask = 1<<(s[i]-'a');
                result++;
            }
            else
            {
                // New char, accumulate to bitMask
                bitMask |= 1<<(s[i]-'a');
            }
        }

        return result;
    }
};
