// 1765. Map of Highest Peak
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int maxVal = 1000*1000;
        m=isWater.size();
        n=isWater[0].size();
        vector<vector<int>> result(m, vector<int>(n, maxVal));

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (isWater[i][j]) result[i][j] = 0;
            }
        }

        int nextR, nextC;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int minNextH = maxVal;

                nextR = i - 1;
                nextC = j;
                if (isValid(nextR, nextC)) {
                    minNextH = min(minNextH, result[nextR][nextC]);
                }

                nextR = i;
                nextC = j - 1;
                if (isValid(nextR, nextC)) {
                    minNextH = min(minNextH, result[nextR][nextC]);
                }

                result[i][j] = min(result[i][j], minNextH+1);
            }
        }

        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                int minNextH = maxVal;

                nextR = i + 1;
                nextC = j;
                if (isValid(nextR, nextC)) {
                    minNextH = min(minNextH, result[nextR][nextC]);
                }

                nextR = i;
                nextC = j + 1;
                if (isValid(nextR, nextC)) {
                    minNextH = min(minNextH, result[nextR][nextC]);
                }

                result[i][j] = min(result[i][j], minNextH+1);
            }
        }

        return result;
    }

private:
    int m, n;
    bool isValid(int r, int c) {
        return r>=0 && r<m && c>=0 && c<n;
    }
};
