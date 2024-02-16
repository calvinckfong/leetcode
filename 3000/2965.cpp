// 2965. Find Missing and Repeated Values
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnt(n*n+1, 0);
        cnt[0] = 1;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                cnt[grid[i][j]]++;
        
        vector<int>::iterator m_ptr = min_element(cnt.begin(), cnt.end());
        vector<int>::iterator r_ptr = max_element(cnt.begin(), cnt.end());

        int missing = (m_ptr-cnt.begin());
        int repeat  = (r_ptr-cnt.begin());

        return {repeat, missing};
    }
};
