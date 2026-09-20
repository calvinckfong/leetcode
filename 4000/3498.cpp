// 3498. Reverse Degree of a String
class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size(), res = 0;
        for (int i=0; i<n; i++) {
            res += (i+1) * (int)(26-s[i]+'a');
        }
        return res;
    }
};
