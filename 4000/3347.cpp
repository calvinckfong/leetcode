// 3347. Maximum Frequency of an Element After Performing Operations II
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> numCount;

        int last=0, res=0, n = nums.size();
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != nums[last]) {
                numCount[nums[last]] = i - last;
                res = max(res, i-last);
                addMode(nums, k, nums[last]);
                last = i;
            }
        }
        
        numCount[nums[last]] = n - last;
        res = max(res, n - last);
        addMode(nums, k, nums[last]);

        for (int m: modes) {
            int l = leftBound(nums, m - k);
            int r = rightBound(nums, m + k);

            int tmp;
            if (numCount.count(m))
                tmp = min(r-l+1, numCount[m] + numOperations);
            else
                tmp = min(r-l+1, numOperations);
            res = max(res, tmp);
        }

        return res;
    }

private:
    set<int> modes;
    void addMode(vector<int>& nums, int k, int value) {
        modes.insert(value);
        if (value-k>=nums.front()) {
            modes.insert(value-k);
        }
        if (value+k<=nums.back()) {
            modes.insert(value+k);
        }
    }

    int leftBound(vector<int>& nums, int value) {
        int l=0, r=nums.size()-1;
        while (l<r) {
            int m = (l+r)/2;
            if (nums[m] < value) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }

    int rightBound(vector<int>& nums, int value) {
        int l=0, r=nums.size()-1;
        while (l<r) {
            int m = (l+r+1)/2;
            if (nums[m] > value) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        return l;
    }
};
