// 77. Combinations
class Solution {
public:
    void combine(int n, int k, vector<vector<int>>& result, vector<int>& curr, int level)
    {
        if (curr.size() == k)
        {
            // length requirement fulfilled
            result.push_back(curr);
            return;
        }

        for (int i=level; i<n; i++)
        {
            // add an element
            curr.push_back(i+1);
            // add new element recursively
            combine(n, k, result, curr, i+1);
            // pop last element
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;
        combine(n, k, result, curr, 0);
        return result;
    }
};
