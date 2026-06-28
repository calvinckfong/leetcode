// 1846. Maximum Element After Decreasing and Rearranging
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int res = 1;

        for (int i=1; i<arr.size(); i++) {
            if (arr[i]>=res+1) {
                res++;
            }
        }

        return res;
    }
};
