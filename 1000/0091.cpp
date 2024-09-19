// 91. Decode Ways
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int n = s.size(), result = 1, tmp;
        for (int i=n-1; i>=0; i--) {
            int curr = s[i]=='0'?0:result;
            if (i<n-1 && (
                s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))) {
                    curr += tmp;
            }
            tmp = result;
            result = curr;
        }
        return result;
    }
};
