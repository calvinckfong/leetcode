// 3495. Minimum Operations to Make Array Elements Zero
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        for (auto& q: queries) {
            long long q0 = q[0];
            long long q1 = q[1];
            long long sum = 0;

            for (long long i=1, j=1; i<=q1; i*=4, j++) {
                int pq0 = max(q0, i);
                int pq1 = min(q1, i*4-1);
                sum += max(0LL, j * (pq1 - pq0 + 1));
            }
            res += (sum+1)/2;
        }
        return res;
    }
};
