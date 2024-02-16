// 216. Combination Sum III
class Solution {
public:
    vector<vector<int>> result;
    void Solve(int k, int n, int start, vector<int>& v)
    {
        if (n==0 && v.size()==k)
            result.push_back(v);
        else if (v.size()==k)
            return;
        
        for (int i=start; i<10; i++)
        {
            if (i<=n)
            {
                v.push_back(i);
                Solve(k, n-i, i+1, v);
                v.pop_back();
            } else break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        for (int i=1; i<10; i++)
        {
            if (i<=n)
            {
                vector<int> v({i});
                Solve(k, n-i, i+1, v);
            }
            else break;
        }

        return result;
    }
};
