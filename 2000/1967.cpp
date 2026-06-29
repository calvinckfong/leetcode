// 1967. Number of Strings That Appear as Substrings in Word
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (string& s: patterns) {
            res += (word.find(s) != string::npos);
        }
        return res;
    }
};
