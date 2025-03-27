// 2780. Minimum Index of a Valid Split
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hashMap1, hashMap2;

        for (auto& n: nums)
            hashMap1[n]++;

        for (int i=0; i<n; i++) {
            int num = nums[i];
            hashMap1[num]--;
            hashMap2[num]++;

            if (hashMap2[num]*2 > i+1 && hashMap1[num]*2 > n-i-1)
                return i;
        }
        return -1;
    }
};
