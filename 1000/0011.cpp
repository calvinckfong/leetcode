// 11. Container With Most Water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1;
        int max_area = (r-l) * min(height[l], height[r]);

        while (r>l)
        {
            if (height[l]>height[r])
                r--;
            else
                l++;
            max_area = max(max_area, (r-l) * min(height[l], height[r]));
        }
        return max_area;
    }
};
