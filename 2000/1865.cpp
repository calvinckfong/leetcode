// 1865. Finding Pairs With a Certain Sum
class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int& n: nums2) {
            cnt[n]++;
        }
    }
    
    void add(int index, int val) {
        cnt[nums2[index]]--;
        nums2[index] += val;
        cnt[nums2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (int& n: nums1) {
            int rest = tot - n;
            if (cnt.count(rest))
                res += cnt[rest];
        }
        return res;
    }

private:
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt;
};
