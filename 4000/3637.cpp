// 3637. Trionic Array I
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums[0]>=nums[1]) return false;
        int inc = 1, dec = 0, is_inc=1;
        int n = nums.size();

        for (int i=2; i<n; i++) {
            if (nums[i]==nums[i-1]) return false;
            if (is_inc) {
                if (nums[i]<=nums[i-1]) {
                    is_inc = 0;
                    dec++;
                }
            } else {
                if (nums[i]>=nums[i-1]) {
                    is_inc = 1;
                    inc++;
                }
            }
        }
        return (inc==2) && (dec==1);
    }
};
