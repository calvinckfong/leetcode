// 492. Construct the Rectangle
class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int W=sqrt(area); W>=1; W--)
        {
            if (area%W == 0) return {area/W, W};
        }
        return {area, 1};
    }
};
