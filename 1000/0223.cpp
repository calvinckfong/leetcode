// 223. Rectangle Area
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // total area = A + B - A&B
        int areaA = (ax2-ax1)*(ay2-ay1);
        int areaB = (bx2-bx1)*(by2-by1);
        int w = (min(ax2, bx2)-max(ax1, bx1));
        int h = (min(ay2, by2)-max(ay1, by1));
        int areaAB = (w>0 && h>0)?w*h:0; // check if overlap
        printf("%d %d %d\n", areaA, areaB, areaAB);
        return areaA + areaB - areaAB;
    }
};
