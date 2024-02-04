// 3024. Type of Triangle II
class Solution {
public:
    string triangleType(vector<int>& nums) {
        auto max_edge = max_element(nums.begin(), nums.end());
        auto min_edge = min_element(nums.begin(), nums.end());
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total<=2**max_edge)
            return "none";
        else if (*max_edge == *min_edge)
            return "equilateral";
        else if (total-*max_edge == 2**min_edge)
            return "isosceles";
        else if (total-*min_edge == 2**max_edge)
            return "isosceles";
        return "scalene";
    }
};
