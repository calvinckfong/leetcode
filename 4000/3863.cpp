// 3863. Minimum Operations to Sort a String
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        char maxc = 'a', minc = 'z';
        if (ranges::is_sorted(s)) return 0;
        if (n==2) return -1;
        for (auto c: s) {
            maxc = max(maxc, c);
            minc = min(minc, c);
        }
        if (s[0]==minc || s[n-1]==maxc) return 1;
        for (int i=1; i<n-1; i++) {
            if (s[i]==minc || s[i]==maxc) return 2;
        }
        return 3;
    }
};
