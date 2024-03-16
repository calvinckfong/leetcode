// 3079. Find the Sum of Encrypted Integers
class Solution {
public:
    int encrypt(int num)
    {
        int maxDigit = 0, digits=0, result=0;
        while (num)
        {
            maxDigit = max(maxDigit, num%10);
            num/=10;
            digits++;
        }
        while (digits--)
            result = result*10 + maxDigit;
        
        return result;
    }

    int sumOfEncryptedInt(vector<int>& nums) {
        int result = 0;
        for (int i=0; i<nums.size(); i++)
            result += encrypt(nums[i]);
        return result;
    }
};
