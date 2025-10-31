// 3289. The Two Sneaky Numbers of Digitville
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int freq[100] = {0};
        for (int n: nums) {
            freq[n]++;
        }

        vector<int> res;
        for (int i=0; i<100; i++) {
            if (freq[i] == 2) res.push_back(i);
        }
        return res;
    }
};
