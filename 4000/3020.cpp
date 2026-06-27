// 3020. Find the Maximum Number of Elements in Subset
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int& x: nums) {
            freq[x]++;
        }

        int res = (freq[1]%2==0) ? freq[1] - 1 : freq[1];
        freq.erase(1);

        for (auto& [_x, _]: freq) {
            int tmp = 0;
            long x = _x;
            for (; freq.contains(x) && freq[x]>1 && x<=1e9; x*=x) {
                tmp+=2;
            }
            res = max(res, tmp+(freq.contains(x)?1:-1));
        }
        return res;
    }
};
