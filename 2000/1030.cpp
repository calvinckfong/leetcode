// 1030. Matrix Cells in Distance Order
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> result;
        vector<array<int, 3>> dists;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
                dists.push_back({i, j, abs(i-rCenter) + abs(j-cCenter)}); // {r, c, distance}
 
        // sort by distance
        sort(dists.begin(), dists.end(), [](array<int, 3>&a, array<int, 3>&b){
            return a[2]<b[2];
        });
        
        for (auto it: dists)
            result.push_back({it[0], it[1]});

        return result;
    }
};
