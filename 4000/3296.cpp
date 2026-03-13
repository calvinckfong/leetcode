// 3296. Minimum Number of Seconds to Make Mountain Height Zero
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxWT = *max_element(workerTimes.begin(), workerTimes.end());
        long long l = 1, r = static_cast<long long>(maxWT) * mountainHeight *
            (mountainHeight+1)/2;
        
        long long res = 0;
        const double eps = 1e-7;
        while (l<=r) {
            long long m = (l+r)/2;
            long long cnt = 0;
            for (int t: workerTimes) {
                long long work = m / t;
                long long k = (sqrt(work*8 + 1)-1) / 2 + eps;
                cnt += k;
            }

            if (cnt >= mountainHeight) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};
