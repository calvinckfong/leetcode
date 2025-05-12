// 2094. Finding 3-Digit Even Numbers
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> nums;
        int n = digits.size();

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=0; k<n; k++) {
                    if (i==j || j==k || k==i) continue;
                    if (digits[i] == 0) continue;
                    if (digits[k]%2) continue;
                    nums.insert(digits[i]*100 + digits[j]*10 + digits[k]);
                }
            }
        }

        vector<int> result(nums.begin(), nums.end());
        sort(result.begin(), result.end());
        return result;
    }
};
