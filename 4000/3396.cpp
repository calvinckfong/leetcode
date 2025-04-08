// 3396. Minimum Number of Operations to Make Elements in Array Distinct
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool visited[101] = {0};
        int n = nums.size();
        for (int i=n-1; i>=0; i--) {
            if (visited[nums[i]])
                return (i/3) + 1;
            visited[nums[i]] = true;
        }
        return 0;
    }
};
