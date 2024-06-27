// 1791. Find Center of Star Graph
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+2;
        int maxCnt=0, result=0;
        vector<int> count(n, 0);
        for (int i=0; i<edges.size(); i++) {
            for (int j=0; j<2; j++) { 
                if (++count[edges[i][j]] > 1) {
                    return edges[i][j];
                }
            }
        }
        return result;
    }
};
