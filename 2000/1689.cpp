// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for (char& c: n) {
            res = max(c-'0', res);
        }
        return res;
    }
};
