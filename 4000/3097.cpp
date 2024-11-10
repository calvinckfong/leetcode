// 3097. Shortest Subarray With OR at Least K II
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k==0) return 1;
        int n = nums.size();
        if (*max_element(nums.begin(), nums.end())>=k) return 1;

        int result = n+1;
        int l=0, r=0;

        while (r<n) {
            // add a num at righer pointer
            updateSum(nums[r], 1);
            while (l<=r && getOrSum()>=k) {
                result = min(result, r-l+1);
                
                // remove a num at left pointer
                updateSum(nums[l], -1);
                l++;
            }
            r++;
        }

        return result == (n+1)?-1:result;
    }

private:
    int orSum[31] = {0};
    void updateSum(int num, int delta) {
        for (int i=0; i<31; i++) {
            orSum[i] += ((num&1)*delta);
            num>>=1;
        }
        cout << "orSum " << orSum << endl;
    }
    int getOrSum() {
        int result = 0;
        for (int i=0; i<31; i++)
            result |= (!!orSum[i])<<i;
        return result;
    }
};
