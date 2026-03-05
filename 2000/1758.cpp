// 1758. Minimum Changes To Make Alternating Binary String
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int start0 = 0, start1 = 0;
        for (int i=0; i<n; i++) {
            (s[i]=='0'+(i%2))?start1++:start0++;
        }
        return min(start0, start1);
    }
};
