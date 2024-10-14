// 2530. Maximal Score After Applying K Operations
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        long long result = 0;
        while (k) {
            int i = pq.top();
            pq.pop();
            int j = pq.top();   // second largest
            do {
                result += i;
                i = (i+2)/3;
                k--;
            } while (k>0 && i>=j);
            pq.push(i);
        }
        return result;
    }
};
