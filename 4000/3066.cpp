// 3066. Minimum Operations to Exceed Threshold Value II
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, std::greater<long>> pq(nums.begin(), nums.end());

        int result = 0;
        while (pq.top()<k) {
            long x = pq.top(); pq.pop();
            long y = pq.top(); pq.pop();
            long sum = min(x,y)*2 + max(x,y);
            pq.push(sum);
            result++;
        }
        return result;
    }
};
