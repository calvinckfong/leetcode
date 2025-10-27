// 2125. Number of Laser Beams in a Bank
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0, prev = 0;
        for (string& s: bank) {
            int cnt = count(s.begin(), s.end(), '1');
            if (cnt>0) {
                res += prev * cnt;
                prev = cnt;
            }
        }
        return res;
    }
};
