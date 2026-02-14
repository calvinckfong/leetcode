// 799. Champagne Tower
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured==0) return 0;
        query_glass = min(query_glass, query_row-query_glass);
        int col = min(query_row, query_glass)+2;

        glasses[0] = poured;
        for (int i=0; i<query_row; i++) {
            int j_init = min(i, query_glass);

            for (int j=j_init; j>=0; j--) {
                double excess = max(0.0, (glasses[j]-1)/2.0);
                glasses[j] = excess;
                glasses[j+1] += excess; 
            }
        }
        return min(1.0, glasses[query_glass]);
    }

private:
    double glasses[52] = {0};
};
