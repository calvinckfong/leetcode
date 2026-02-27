// 3666. Minimum Operations to Equalize Binary String
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int zeros = 0;
        for (int i=0; i<n; i++) zeros += (s[i] == '0');
        int ones = n - zeros;
        int m = (zeros + k - 1) / k;

        while (m<=n) {
            long total = (long)m * k;

            if ((total-zeros)&1) {
                m++;
                continue;
            }

            int max0 = 0, max1 = 0;
            if (m&1) {
                max0 = m;
                max1 = m - 1;
            } else {
                max0 = m - 1;
                max1 = m;
            }

            long l = max((long)zeros, total - (long)ones * max1);
            long r = min((long)zeros*max0, (long)total);

            if (l <= r) {
                if ((l&1) == (zeros&1) || l+1<=r) {
                    return m;
                }
            }
            m++;
        }

        return -1;
    }
};
