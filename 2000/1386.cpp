// 1386. Cinema Seat Allocation
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> occupied;
        for (auto& s: reservedSeats) {
            if (s[1]>=2 && s[1]<=9) {
                occupied[s[0]] |= (1 << (s[1]-2));
            }
        }

        const int LEFT  = 0b11110000;
        const int MID   = 0b11000011;
        const int RIGHT = 0b00001111;
        int res = (n - occupied.size()) * 2;
        for (auto& [r, bm] : occupied) {
            res += (((bm|LEFT)==LEFT) || 
                    ((bm|MID) == MID) || 
                    ((bm|RIGHT)==RIGHT) );
        }
        return res;
    }
};
