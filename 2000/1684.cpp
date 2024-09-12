// 1684. Count the Number of Consistent Strings
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool flags[26] = {false};
        for (char c: allowed) {
            flags[c-'a'] = true;
        }

        bool isAllowed;
        int result = 0;
        for (string& s: words) {
            isAllowed = true;
            for (char& c: s) {
                if (!flags[c-'a']) {
                    isAllowed = false;
                    break;
                }
            }
            result += isAllowed;
        }
        return result;
    }
};
