// 2997. Minimum Number of Operations to Make Array XOR Equal to K
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=k;
        for (int n: nums)
            sum = sum^n; 

        int result = 0;
        for (int i=0; i<32; i++) {
            if (sum&1) result++;
            sum>>=1;
        }
        return result;
    }
};
