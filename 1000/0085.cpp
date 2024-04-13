// 85. Maximal Rectangle
class Solution {
public:
    int m, n;
    int maxArea(vector<int>& heights) {
        stack<int> stk;
        int maxA = 0;
        
        for (int i=0; i<n; i++) 
        {
            while (!stk.empty() && (heights[stk.top()]>=heights[i]))
            {
                int h = heights[stk.top()];
                stk.pop();
                int w = (stk.empty())? i : i-stk.top()-1;
                maxA = max(maxA, w*h);
            }
            stk.push(i);
        }

        while (!stk.empty()) 
        {
            int h = heights[stk.top()];
            stk.pop();
            int w = (stk.empty())? n : n-stk.top()-1;
            maxA = max(maxA, w*h);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        m=matrix.size(), n=matrix[0].size();
        int result=0;
        vector<int> heights(n, 0);
        for (int i=0; i<m; i++)
        {
            // accumulate the heights for each column 
            for (int j=0; j<n; j++)
                if (matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            
            // compute the areas and find the max
            result = max(result, maxArea(heights));
        }

        return result;
    }
};
