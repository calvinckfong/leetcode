// 3394. Check if Grid can be Cut into Sections
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return check(rectangles, XDIM) || check(rectangles, YDIM);
    }

private:
    const int XDIM=0, YDIM=1;

    bool check(vector<vector<int>>& rect, const int dim) {
        sort(rect.begin(), rect.end(), 
            [dim](const vector<int>& a, const vector<int>& b){
                return a[dim] < b[dim]; });
        
        int border = rect[0][dim+2];
        int n = rect.size();
        int gapCnt = 0;

        for (int i=1; i<n; i++) {
            vector<int>& r = rect[i];
            if (border <= r[dim]) gapCnt++;
            border = max(border, r[dim+2]);
        }
        return gapCnt > 1;
    }
};
