// 3542. Minimum Operations to Convert All Elements to Zero
class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> tmp;
        int res = 0;
        for (int& x: nums) {
            while (!tmp.empty() && tmp.back()>x) {
                tmp.pop_back();
            }
            if (x==0) continue;
            if (tmp.empty() || tmp.back()<x) {
                res++;
                tmp.push_back(x);
            }
        }
        return res;
    }
};
