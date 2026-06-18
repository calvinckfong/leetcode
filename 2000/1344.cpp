// 1344. Angle Between Hands of a Clock
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m = static_cast<double>(minutes) / 60.0;
        double h = static_cast<double>(hour) / 12.0;
        double ret = fabs(m - h - m/12.0)*360;
        return (ret > 180.0) ? 360.0-ret : ret;
    }
};
