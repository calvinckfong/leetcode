// 1401. Circle and Rectangle Overlapping
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        long long d = 0;
        if (xCenter<x1 || xCenter>x2) {
            d += dist(x1, x2, xCenter);
        }
        if (yCenter<y1 || yCenter>y2) {
            d += dist(y1, y2, yCenter);
        }
        return d <= radius * radius;
    }

private:
    long long dist(int v1, int v2, int c) {
        long long d1 = v1-c;
        long long d2 = v2-c;
        return min(d1*d1, d2*d2);
    }
};
