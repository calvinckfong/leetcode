// 1385. Find the Distance Value Between Two Arrays
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for (auto x: arr1) {
            for (auto y: arr2) {
                if (abs(x-y)<=d) goto end;
            }
            res++;
end:
        }
        return res;
    }
};
