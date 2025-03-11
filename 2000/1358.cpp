// 1358. Number of Substrings Containing All Three Characters
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), l=0, r=0;
        int count[3] = {0};
        int result = 0;

        while (r<n) {
            char c = s[r];
            count[c-'a']++;

            while (count[0]>0 && count[1]>0 && count[2]>0) {
                result += (n - r);
                c = s[l];
                count[c-'a']--;
                l++;
            }
            r++;
        }
        return result;
    }
};
