// 384. Shuffle an Array
class Solution {
public:
    int n;
    vector<int> original, suffled;
    Solution(vector<int>& nums) {
        original = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        suffled = original;
        for (int i=0; i<n*2; i++)
            swap(suffled[rand()%n], suffled[rand()%n]);
        return suffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
