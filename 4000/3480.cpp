// 3480. Maximize Subarrays After Removing One Conflicting Pair
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> min1(n+1, INT_MAX), min2(n+1, INT_MAX);
        for (vector<int>& p: conflictingPairs) {
            int minVal, maxVal;
            if (p[0]>p[1]) {
                minVal = p[1]; maxVal = p[0];
            } else {
                minVal = p[0]; maxVal = p[1];
            }

            if (min1[minVal] > maxVal) {
                min2[minVal] = min1[minVal];
                min1[minVal] = maxVal;
            } else if (min2[minVal] > maxVal) {
                min2[minVal] = maxVal;
            }
        }

        long long res = 0;
        vector<long long> delCnt(n+1, 0);
        for (int i=n, j=n, k=INT_MAX; i>=1; i--) {
            if (min1[j] > min1[i]) {
                k = min(k, min1[j]);
                j = i;
            } else {
                k = min(k, min1[i]);
            }
            res += min(min1[j], n+1) - i;
            delCnt[j] += min(min(k, min2[j]), n+1) - min(min1[j], n+1); 
        }
        return res + *max_element(delCnt.begin(), delCnt.end());
    }
};
