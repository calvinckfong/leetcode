// 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int l,r,h,n=height.size();
        int result = 0;
        // left to right
        l=0, r=0;
        while (r<n) {
            if (height[r]>=height[l] && r>l) {
                h = height[l++];
                while (l<r) {
                    result += h-height[l++];
                }
            }
            r++;
        }

        // right to left
        l=n-1, r=n-1;
        while (l>=0) {
            if (height[l]>height[r]) {
                h = height[r--];
                while (r>l) {
                    result += h-height[r--];
                }
            }
            l--;
        }
        return result;
    }
};
