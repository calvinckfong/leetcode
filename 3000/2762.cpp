// 2762. Continuous Subarrays
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        auto greater = [&nums](int a, int b) {
            return nums[a] < nums[b];
        };

        auto less = [&nums](int a, int b) {
            return nums[a] > nums[b];
        };

        priority_queue<int, vector<int>, function<bool(int, int)>> maxHeap(greater);
        priority_queue<int, vector<int>, function<bool(int, int)>> minHeap(less);

        int l=0, r=0, n=nums.size();
        long long result = 0;
        while (r<n) {
            maxHeap.push(r);
            minHeap.push(r);

            while (l<r && (nums[maxHeap.top()]-nums[minHeap.top()]>2)) {
                l++;

                while (!maxHeap.empty() && maxHeap.top()<l)
                    maxHeap.pop();

                while (!minHeap.empty() && minHeap.top()<l)
                    minHeap.pop();
            } 

            result += r-l+1;
            r++;
        }
        return result;
    }
};
