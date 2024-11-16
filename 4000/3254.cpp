// 3254. Find the Power of K-Size Subarrays I
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size(), maxVal=-1;
        vector<int> result(n-k+1, -1);

        int i=0;
        while (i<=n-k) {
            if (maxVal==-1) {
                // case 1: no consecutive seqeunce before
                maxVal = nums[i];
                for (int j=i+1; j<i+k; j++) {
                    if (nums[j] != ++maxVal ) {
                        maxVal = -1;
                        i = j;
                        break;
                    }
                }
                if (maxVal>0) {
                    result[i] = maxVal;
                    i++;
                }
            } else if (nums[i+k-1] == maxVal+1) {
                // case 2: with consecutive seq and continue at next element
                result[i] = ++maxVal;
                i++;
            } else {
                // case 3: with consecutive seq but discontinue at next element
                i = i+k-1;
                maxVal = -1;
            }
        }
        return result;
    }
};
