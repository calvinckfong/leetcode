// 2206. Divide Array Into Equal Pairs
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[502] = {0};
        for (auto n: nums)
            freq[n]++;
        for (int i=0; i<502; i++)
            if (freq[i] % 2) return false;
        return true;
    }
};
