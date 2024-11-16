// 303. Range Sum Query - Immutable
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums = vector<int>(n+1, 0);

        for (int i=0, sum=0; i<n; i++) {
            sum += nums[i];
            sums[i+1] = sum;
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right+1] - sums[left];
    }

private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
