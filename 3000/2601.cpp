// 2601. Prime Subtraction Operation
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> isPrime(maxVal+1, 1);
        isPrime[1] = 0;
        for (int i=2; i<=sqrt(maxVal+1); i++) {
            if (isPrime[i]==1) {
                for (int j=i*i; j<=maxVal; j+=i)
                    isPrime[j] = 0;
            }
        }

        int i=0, last=1;
        while (i<n) {
            int diff = nums[i] - last;
            if (diff < 0) return false;

            if (isPrime[diff] || diff==0) {
                i++;
            }
            last++;
        }
        return true;
    }
};
