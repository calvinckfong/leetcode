// 2833. Furthest Point From Origin
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int res = 0, space = 0;
        for (char& c: moves) {
            if (c == 'L') {
                res--;
            } else if (c == 'R') {
                res++;
            } else {
                space++;
            }
        }
        return (res>0)?space+res : space-res;
    }
};
