// 22. Generate Parentheses
class Solution {
public:
    vector<string> result;
    void Generate(int open, int close, string curr)
    {
        if (!open && !close)
        {
            result.push_back(curr);
            return;
        }

        if (open>0)
        {
            Generate(open-1, close, curr + "(");
        }
        if (close>open)
        {
            Generate(open, close-1, curr + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        Generate(n, n, "");
        //return vector<string>(result.begin(), result.end());
        return result;
    }
};
