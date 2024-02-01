// 66. Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for (int i=n-1; i>=0; i--)
        {
            digits[i] = (digits[i] + carry)%10;
            carry = digits[i]==0;
            if (!carry) break;
        }
        if (carry)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};
