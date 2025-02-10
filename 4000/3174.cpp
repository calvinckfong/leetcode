// 3174. Clear Digits
class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        string result;
        for (int i=0; i<n; i++) {
            if (s[i]>='0' && s[i]<='9') {
                if (result.size()>0) result.pop_back();
            } else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
