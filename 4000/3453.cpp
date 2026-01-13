// 3453. Separate Squares I
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total_area = 0;
        vector<tuple<int, int, int>> events;
        for (auto& s: squares) {
            int y=s[1], l=s[2];
            total_area += (long long)l*l;
            events.emplace_back(y, l, 1);
            events.emplace_back(y+l, l, -1);
        }
        sort(events.begin(), events.end(), [](const auto& a, const auto& b){
            return get<0>(a) < get<0>(b);
        });

        double prev_h = 0;
        double cover_w = 0;
        double curr_a = 0;
        for (const auto&[y, l, delta]: events) {
            int diff = y - prev_h;
            double area = cover_w * diff;
            if (2LL*(curr_a+area) >= total_area) {
                return prev_h + (total_area - 2.0*curr_a) / (2.0*cover_w);
            }
            cover_w += delta*l;
            curr_a += area;
            prev_h = y;
        }
        return 0.0;
    }
};
