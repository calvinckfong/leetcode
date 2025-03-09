// 3208. Alternating Groups II
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int result = 0;
        int l=0, r=0, last=-1;

        while (r<n+k-1) {
            if (colors[r%n] != last) {
                last = colors[r%n];
                if (r-l+1 == k) {
                    result++;
                    l++;
                }
            } else {
                l = r;
            }
            r++;
        }
        return result;
    }
};
