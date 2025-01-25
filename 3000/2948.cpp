// 2948. Make Lexicographically Smallest Array by Swapping Elements
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int currGrp = 0;
        unordered_map<int, int> numInGrp;
        unordered_map<int, list<int>> grpToList;
        numInGrp.insert({sorted[0], currGrp});
        grpToList.insert({currGrp, {sorted[0]}});

        for (int i=1; i<nums.size(); i++) {
            if (abs(sorted[i] - sorted[i-1])>limit) currGrp++;

            numInGrp.insert({sorted[i], currGrp});

            if (grpToList.find(currGrp) == grpToList.end())
                grpToList[currGrp] = {};

            grpToList[currGrp].push_back(sorted[i]);
        }

        for (int i=0; i<nums.size(); i++) {
            int num = nums[i];
            int grp = numInGrp[num];
            nums[i] = *grpToList[grp].begin();
            grpToList[grp].pop_front();
        }

        return nums;
    }
};
