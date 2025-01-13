// 3223. Minimum Length of String After Operations
class Solution {
public:
    int minimumLength(string s) {
        int freq[26] = {0};
        int result = 0;

        for (char c: s) freq[c-'a']++;

        for (int f: freq) {
            if (f==0) continue;
            if (f%2==0) result += 2;
            else result++;
        }

        return result;
    }
};
