// 2981. Find Longest Special Substring That Occurs Thrice I
class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> freq;
        int n=s.size();
        for (int i=0; i<n; i++) {
            char startChar = s[i];
            int len = 0;
            for (int j=i; j<n; j++) {
                if (startChar == s[j]) {
                    len++;
                    freq[{startChar, len}]++;
                } else {
                    break;
                }
            }
        }

        int result = -1;
        for (auto f: freq) {
            if (f.second>=3) result = max(result, f.first.second);
        }

        return result;
    }
};
