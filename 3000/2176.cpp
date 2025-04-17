// 2176. Count Equal and Divisible Pairs in an Array
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size(), result = 0;
        
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                result += ( ((i*j)%k==0) && (nums[i]==nums[j]) );
            }
        }

        return result;
    }
};
