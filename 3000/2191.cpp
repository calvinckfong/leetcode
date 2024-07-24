// 2191. Sort the Jumbled Numbers
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, int>> list(n);
        for (int i=0; i<n; i++) {
            int num = nums[i], mapped = 0, factor=1;
            do {
                mapped += mapping[num%10]*factor;
                num/=10;
                factor*=10;
            } while (num>0);
            list[i] = {mapped, i};
        }
        sort(list.begin(), list.end());
        vector<int> result(n);
        for (int i=0; i<n; i++)
            result[i] = nums[list[i].second];
        return result;
    }
};
