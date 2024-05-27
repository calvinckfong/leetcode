// 1608. Special Array With X Elements Greater Than or Equal X
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int result=0, n=nums.size();
        sort(nums.rbegin(), nums.rend());
        while (result<=n) {
            int cnt = 0;
            for (int i: nums) cnt += (i>=result);
            if (result == cnt) return result;
            result++;
        }
        return -1;
    }
};
