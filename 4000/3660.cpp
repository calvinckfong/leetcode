// 3660. Jump Game IX
class Solution {
    struct Item {
        int value;
        int left, right;
    };

public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<Item> stack;

        for (int i=0; i<n; i++) {
            Item curr = {nums[i], i, i};

            while (!stack.empty() && stack.back().value>nums[i]) {
                Item top = stack.back();
                stack.pop_back();
                curr.value = max(curr.value, top.value);
                curr.left = top.left;
            }
            stack.push_back(curr);
        }

        for (int i=0; i<stack.size(); i++) {
            for (int j=stack[i].left; j<=stack[i].right; j++) {
                res[j] = stack[i].value;
            }
        }
        return res;
    }
};
