// 3289. The Two Sneaky Numbers of Digitville
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int, int> freq;
        for (int n: nums) {
            freq[n]++;
        }

        vector<int> res;
        for (auto& p: freq) {
            if (p.second == 2) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};
