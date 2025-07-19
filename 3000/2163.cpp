// 2163. Minimum Difference in Sums After Removal of Elements
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n3 = nums.size();
        int n  = n3/3;

        // Accumulate first third
        long long sum = 0;
        priority_queue<int> pq1;
        for (int i=0; i<n; i++) {
            int& num = nums[i];
            sum += num;
            pq1.push(num);
        }

        // Append second third 
        // and remove smallest for sum
        vector<long long> p1(n+1);
        p1[0] = sum;
        for (int i=n; i<2*n; i++) {
            int& num = nums[i];
            sum += num;
            pq1.push(num);
            sum -= pq1.top();
            pq1.pop();
            p1[i-n+1] = sum; 
        }

        // Accumulate last third as p2
        long long p2 = 0;
        priority_queue<int, vector<int>, greater<>> pq2;
        for (int i=n3-1; i>=n*2; i--) {
            int& num = nums[i];
            p2 += num;
            pq2.push(num);
        }

        // Append second third to p2
        // and remove biggest 
        long long res = p1[n] - p2;
        for (int i=2*n-1; i>=n; i--) {
            int& num = nums[i];
            p2 += num;
            pq2.push(num);
            p2 -= pq2.top();
            pq2.pop();
            res = min(res, p1[i-n]-p2);
        }
        return res;
    }
};
