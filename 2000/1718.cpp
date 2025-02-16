// 1718. Construct the Lexicographically Largest Valid Sequence
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        resultSize = 2*n-1;
        vector<int> result(resultSize, 0);
        vector<bool> used(n+1, false);

        solve(0, result, used, n);

        return result;
    }

private:
    int resultSize;
    bool solve(int currIdx, vector<int>& result, vector<bool>& used, int n) {
        if (currIdx == resultSize) return true;

        if (result[currIdx] != 0) {
            return solve(currIdx+1, result, used, n);
        } 

        for (int i=n; i>=1; i--) {
            if (used[i]) continue;

            used[i] = true;
            result[currIdx] = i;
            
            int next = currIdx+i;
            if (i==1) {
                if (solve(currIdx+1, result, used, n)) {
                    return true;
                }
            }
            else if (next<resultSize && result[next]==0) {
                result[next] = i;
                if (solve(currIdx+1, result, used, n)) return true;
                result[next] = 0;
            }

            result[currIdx] = 0;
            used[i] = false;
        }
        return false;
    }
};
