// 912. Sort an Array
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }

private:
    void mergeSort(vector<int>& nums, int l, int h) {
        if (l>=h) return;
        if (h-l==1 && nums[l]>nums[h]) {
            swap(nums[l], nums[h]);
            return;
        }
        int m = (h+l)/2;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, h);
        mergeArray(nums, l, m, h);
    }

    void mergeArray(vector<int>& nums, int lo, int mid, int hi) {
        vector<int> lhs(nums.begin()+lo, nums.begin()+mid+1);
        vector<int> rhs(nums.begin()+mid+1, nums.begin()+hi+1);        

        int l=0, r=0, p=lo;
        while (l<lhs.size() && r<rhs.size()) {
            if (lhs[l] < rhs[r]) nums[p] = lhs[l++];
            else nums[p] = rhs[r++];
            p++;
        }
        while (l<lhs.size()) nums[p++] = lhs[l++];
        while (r<rhs.size()) nums[p++] = rhs[r++];
    }
};
