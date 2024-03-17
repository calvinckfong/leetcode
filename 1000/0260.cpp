// 260. Single Number III
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i=0; i<nums.size(); i++)
            cnt[nums[i]]++;

        vector<int> result(2,0);
        int k=0;
        for (auto it:cnt)
        {
            if (it.second==1) result[k++] = it.first;
            if (k==2) break;
        }

        return result;
    }
};
