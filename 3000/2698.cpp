// 2698. Find the Punishment Number of an Integer
class Solution {
public:
    int punishmentNumber(int n) {
        int result = 0;
        for (int i=0; i<=n; i++) {
            int sq = i*i;
            if (partitionable(sq, i))
                result += sq;
        }
        return result;
    }

private:
    bool partitionable(int sq, int i) {
        if (i<0 || sq<i) return false;
        if (sq == i) return true;

        return  partitionable(sq/10, i - sq%10) ||
                partitionable(sq/100, i - sq%100) ||
                partitionable(sq/1000, i - sq%1000);
    }
};
