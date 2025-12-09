// 3583. Count Special Triplets
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        pos.reserve(n*2);

        for (int i=0; i<n; i++) {
            pos[nums[i]].push_back(i);
        }

        int res = 0;
        for (int i=1; i<n-1; i++) {
            int tar = nums[i] * 2;
            if (pos.count(tar) == 0) continue;

            const auto& arr = pos[tar];
            if (arr.size()<=1 || arr[0]>=i) continue;

            auto split = upper_bound(arr.begin(), arr.end(), i);
            long l = split - arr.begin();
            long r = arr.size() - l;
            if (nums[i] == 0) l--;
            res = (res + (l*r) % MOD) % MOD;
        }
        return res;
    }
};
