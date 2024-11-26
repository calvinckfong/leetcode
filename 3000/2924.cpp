// 2924. Find Champion II
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        for (vector<int>& e: edges) {
            inDegree[e[1]]++;
        }

        int champNode = -1, champCnt = 0;
        for (int i=0; i<n; i++) {
            if (inDegree[i]==0) {
                champNode = i;
                champCnt++;
            }
        }

        return (champCnt>1) ? -1 : champNode;
    }
};
