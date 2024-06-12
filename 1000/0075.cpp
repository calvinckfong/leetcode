// 75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int freq[3] = {0}, n=nums.size();
        for (int i=0; i<n; i++) {
            freq[nums[i]]++;
        }
        for (int i=0, k=0; i<3; i++) {
            for (int j=0; j<freq[i]; j++)
                nums[k++] = i;
        }
    }
};
