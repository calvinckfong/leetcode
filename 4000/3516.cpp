// 3516. Find Closest Person
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d = abs(x-z) - abs(y-z);
        return (d<0) ? 1 : (d>0) ? 2 : 0;
    }
};
