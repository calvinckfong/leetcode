// 1394. Find Lucky Integer in an Array
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int& x: arr) {
            freq[x]++;
        }

        int res = -1;
        for (auto& p: freq) {
            if (p.first == p.second && p.first > res)
                res = p.first;
        }

        return res;
    }
};
