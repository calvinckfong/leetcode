// 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int l,r,h,n=height.size();
        int sum, result = 0;

        // left to right
        l=0, r=0, h=height[l], sum=0;
        while (r<n) {
            if (h<=height[r] && r>l) {
                result += sum;
                sum = 0;
                h = height[r];
                l=r;
            } else {
                sum += h-height[r];
            }
            r++;
        }

        // right to left
        l=n-1, r=n-1, h=height[l], sum=0;
        while (l>=0) {
            if (h<height[l]) {
                result += sum;
                sum = 0;
                h = height[l];
            } else {
                sum += h-height[l];
            }
            l--;
        }

        return result;
    }
};
